/*
 * panedlist.c
 *
 * Copyright 2013-2018 AmatCoder
 *
 * This file is part of Mednaffe.
 *
 * Mednaffe is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mednaffe is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Mednaffe; if not, see <http://www.gnu.org/licenses/>.
 *
 *
 */


#include <string.h>
#include "widgets/marshallers.h"
#include "panedlist.h"
#include "panedimage.h"


typedef struct _PanedListClass PanedListClass;
typedef struct _PanedListPrivate PanedListPrivate;

struct _PanedListClass {
  GtkPanedClass parent_class;
};

struct _PanedListPrivate {
  gulong handler_id;
  gchar* filters;
  GtkTreeView* treeview;
  GtkTreeViewColumn* games_column;
  GtkTreeSelection* games_selection;
  GtkListStore* games_store;
  GtkCellRenderer* renderer;
  PanedImage* panedimage;
};


enum  {
  PANED_LIST_FILLED_SIGNAL,
  PANED_LIST_MOUSE_RELEASED_SIGNAL,
  PANED_LIST_ITEM_SELECTED_SIGNAL,
  PANED_LIST_LAUNCHED_SIGNAL,
  PANED_LIST_NUM_SIGNALS
};

static guint paned_list_signals[PANED_LIST_NUM_SIGNALS] = {0};


G_DEFINE_TYPE_WITH_PRIVATE (PanedList, paned_list, GTK_TYPE_PANED);


static void
paned_list_selection_changed (GtkTreeSelection* _sender,
                              gpointer self)
{
  GtkTreeModel* model;
  GtkTreeIter iter;

  g_return_if_fail (self != NULL);

  PanedList* pl = self;
  PanedListPrivate* priv = paned_list_get_instance_private(pl);

  gboolean valid = gtk_tree_selection_get_selected (priv->games_selection, &model, &iter);

  if (valid)
  {
    gchar* str;
    gchar* str2;
    gchar* str3;

    gtk_tree_model_get ((GtkTreeModel*) priv->games_store, &iter, 0, &str, 1, &str2, 2, &str3, -1);

    g_free (pl->selected);
    pl->selected = str3;

    paned_image_set_images (priv->panedimage, str2);
    g_free(str2);

    g_signal_emit (pl, paned_list_signals[PANED_LIST_ITEM_SELECTED_SIGNAL], 0, str);
    g_free(str);
  }
}


static void
paned_list_row_double_clicked (GtkTreeView* _sender,
                               GtkTreePath* path,
                               GtkTreeViewColumn* column,
                               gpointer self)
{

  g_return_if_fail (self != NULL);

  PanedList* pl = self;

  g_signal_emit (pl, paned_list_signals[PANED_LIST_LAUNCHED_SIGNAL], 0, pl->selected);
}


static gboolean
paned_list_key_press (GtkWidget* _sender,
                      GdkEventKey* event,
                      gpointer self)
{
  g_return_val_if_fail (self != NULL, FALSE);
  g_return_val_if_fail (event != NULL, FALSE);

  PanedList* pl = self;

  if (event->keyval == 65293)
  {
    g_signal_emit (pl, paned_list_signals[PANED_LIST_LAUNCHED_SIGNAL], 0, pl->selected);
    return TRUE;
  }

  return FALSE;
}


static void
paned_list_scan_dir (PanedList* self,
                     const gchar* path,
                     GSList* filters,
                     gboolean recursive)
{
  g_return_if_fail (self != NULL);
  g_return_if_fail (path != NULL);

  PanedListPrivate* priv = paned_list_get_instance_private(self);

  GDir* dir = g_dir_open (path, 0, NULL);

  if (dir == NULL)
    return;

  gint i = 0;

  while (TRUE)
  {
    const gchar* name = g_dir_read_name (dir);

    if (name == NULL)
      break;

    gchar* path2 = g_build_filename (path, name, NULL);

    if (g_file_test (path2, G_FILE_TEST_IS_REGULAR))
    {
      gboolean b = FALSE;

      if (filters != NULL)
      {
        GSList* item_it = NULL;
        for (item_it = filters; item_it != NULL; item_it = item_it->next)
        {
          GPatternSpec* item = (GPatternSpec*) item_it->data;

          if (g_pattern_match (item, strlen (name), name, NULL))
          {
            b = TRUE;
            break;
          }
        }
      } else b = TRUE;

      if (b)
      {
        GtkTreeIter iter;
        gchar* s;
        gchar* e;

        e = g_strrstr (name, ".");

        if (e != NULL)
        {
          gint z = e - name;
          s = g_strndup (name, z);
        }
        else
          s = g_strdup (name);

        gtk_list_store_append (priv->games_store, &iter);
        gtk_list_store_set (priv->games_store, &iter, 0, name, 1, s, 2, path2, -1);
        i++;
        g_free (s);
      }
    }

    if ((g_file_test (path2, G_FILE_TEST_IS_DIR)) && (recursive))
      paned_list_scan_dir (self, path2, filters, recursive);

    g_free (path2);
  }

  g_signal_emit (self, paned_list_signals[PANED_LIST_FILLED_SIGNAL], 0, i);

  g_dir_close (dir);
}


static void
select_first (PanedList* self)
{
  g_return_if_fail (self != NULL);

  GtkTreeIter iter;
  PanedListPrivate* priv = paned_list_get_instance_private(self);

  if (gtk_tree_model_get_iter_first ((GtkTreeModel*) priv->games_store, &iter))
    gtk_tree_selection_select_iter (priv->games_selection, &iter);

  gtk_widget_grab_focus ((GtkWidget*) priv->treeview);
}


void
paned_list_show_filters (PanedList* self,
                         gboolean b)
{
  g_return_if_fail (self != NULL);

  PanedListPrivate* priv = paned_list_get_instance_private(self);

  if ((b) && (g_strcmp0 (priv->filters, "") != 0))
  {
    gchar* title = g_strconcat ("Games (", priv->filters,")", NULL);
    gtk_tree_view_column_set_title (priv->games_column, title);
    g_free (title);
  }
  else
    gtk_tree_view_column_set_title (priv->games_column, "Games");
}


void
paned_list_fill_list (PanedList* self,
                      GtkListStore* store,
                      GtkTreeIter* iter)
{
  gchar* path;
  gchar* path_img_a;
  gchar* path_img_b;
  gboolean recursive;
  gboolean hidden;
  gint vpos;
  gint hpos;
  gchar** lines;
  GSList* list = NULL;

  g_return_if_fail (self != NULL);
  g_return_if_fail (store != NULL);

  PanedListPrivate* priv = paned_list_get_instance_private(self);

  if (iter == NULL)
  {
    g_signal_emit (self, paned_list_signals[PANED_LIST_FILLED_SIGNAL], 0, 0);
    return;
  }

  g_signal_handler_block (priv->games_selection, priv->handler_id);
  gtk_list_store_clear (priv->games_store);

  g_free (priv->filters);

  gtk_tree_model_get ((GtkTreeModel*) store, iter, 0, &path,
                                                   1, &recursive,
                                                   2, &hidden,
                                                   3, &priv->filters,
                                                   4, &path_img_a,
                                                   5, &path_img_b,
                                                   6, &vpos,
                                                   7, &hpos,
                                                   -1);

  if (hidden)
    gtk_tree_view_column_set_attributes (priv->games_column, priv->renderer, "text", 1, NULL);
  else
    gtk_tree_view_column_set_attributes (priv->games_column, priv->renderer, "text", 0, NULL);


  lines = g_strsplit (priv->filters, " ", 0);

  if (lines[0])
  {
    gint i = 0;
    GPatternSpec* spec;

    while (TRUE)
    {
      const gchar* str = lines[i];

      if (str)
      {
        spec = g_pattern_spec_new (str);
        list = g_slist_append (list, spec);
      }
      else
        break;

    i++;
    }
  }

  paned_image_set_paths (priv->panedimage, path_img_a, path_img_b);
  paned_list_scan_dir (self, path, list, recursive);

  GtkAllocation alloc;
  gtk_widget_get_allocation ((GtkWidget*) self, &alloc);

  if ((vpos == 0) && ((path_img_a[0] != '\0') || (path_img_b[0] != '\0')))
    vpos = alloc.width / 2;

  gtk_paned_set_position ((GtkPaned*) self, (alloc.width - vpos));
  //gtk_paned_set_position ((GtkPaned*) priv->panedimage, (alloc.height - hpos)); /* FIXME: This does not work (gtk bug?) */

  paned_list_show_filters (self, self->filters_header);

  g_signal_handler_unblock (priv->games_selection, priv->handler_id);

  select_first(self);

  g_strfreev(lines);
  g_slist_free_full (list, (GDestroyNotify) g_pattern_spec_free);

  g_free (path_img_b);
  g_free (path_img_a);
  g_free (path);
}


static gboolean
button_release (GtkWidget *widget,
                GdkEvent *event,
                gpointer self)
{
  PanedListPrivate* priv = paned_list_get_instance_private(self);

  GtkAllocation alloc;
  gtk_widget_get_allocation (widget, &alloc);
  g_signal_emit (self,
                 paned_list_signals[PANED_LIST_MOUSE_RELEASED_SIGNAL],
                 0,
                 (alloc.width - gtk_paned_get_position((GtkPaned*) self)),
                 (alloc.height - gtk_paned_get_position((GtkPaned*) priv->panedimage)));

  return FALSE;
}


static void
paned_list_finalize (GObject * obj)
{
  PanedList * self = G_TYPE_CHECK_INSTANCE_CAST (obj, paned_list_get_type (), PanedList);
  PanedListPrivate* priv = paned_list_get_instance_private(self);

  g_free (priv->filters);
  g_free (self->selected);

  G_OBJECT_CLASS (paned_list_parent_class)->finalize (obj);
}


PanedList*
paned_list_new (void)
{
  PanedList * self = (PanedList*) g_object_new (paned_list_get_type (), NULL);
  PanedListPrivate* priv = paned_list_get_instance_private(self);

  GtkScrolledWindow* scrolled;

  priv->games_store = gtk_list_store_new (3, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, -1);
  priv->treeview = (GtkTreeView*) gtk_tree_view_new_with_model ((GtkTreeModel*) priv->games_store);
  g_object_unref (priv->games_store);

  priv->renderer = (GtkCellRenderer*) gtk_cell_renderer_text_new ();
  priv->games_column = gtk_tree_view_column_new_with_attributes ("Games", priv->renderer, "text", 0, NULL, NULL);


  gtk_tree_view_column_set_clickable (priv->games_column, TRUE);
  gtk_tree_view_column_set_sort_column_id (priv->games_column, 0);
  gtk_tree_view_insert_column (priv->treeview, priv->games_column, 0);

  priv->games_selection = gtk_tree_view_get_selection (priv->treeview);

  scrolled = (GtkScrolledWindow*) gtk_scrolled_window_new (NULL, NULL);
  gtk_container_add ((GtkContainer*) scrolled, (GtkWidget*) priv->treeview);
  gtk_paned_pack1 ((GtkPaned*) self, (GtkWidget*) scrolled, TRUE, TRUE);

  priv->panedimage = paned_image_new (GTK_ORIENTATION_VERTICAL);
  gtk_paned_pack2 ((GtkPaned*) self, (GtkWidget*) priv->panedimage, FALSE, TRUE);

  gtk_widget_show_all ((GtkWidget*) self);

  g_signal_connect_object ((GtkWidget*) priv->treeview,
                           "key-press-event",
                           (GCallback) paned_list_key_press,
                           self,
                           0);

  g_signal_connect_object (priv->treeview,
                           "row-activated",
                           (GCallback) paned_list_row_double_clicked,
                           self,
                           0);

  g_signal_connect_object ((GtkWidget*) self,
                           "button-release-event",
                           (GCallback) button_release,
                           self,
                           0);

  priv->handler_id = g_signal_connect_object (priv->games_selection,
                                              "changed",
                                              (GCallback) paned_list_selection_changed,
                                              self,
                                              0);

  gtk_tree_view_column_clicked (priv->games_column);

  return self;
}


static void
paned_list_init (PanedList * self)
{
}


static void
paned_list_class_init (PanedListClass * klass)
{
  G_OBJECT_CLASS (klass)->finalize = paned_list_finalize;

  paned_list_signals[PANED_LIST_FILLED_SIGNAL] = g_signal_new ("filled",
                                                               paned_list_get_type (),
                                                               G_SIGNAL_RUN_LAST,
                                                               0,
                                                               NULL,
                                                               NULL,
                                                               g_cclosure_marshal_VOID__INT,
                                                               G_TYPE_NONE,
                                                               1,
                                                               G_TYPE_INT);

  paned_list_signals[PANED_LIST_MOUSE_RELEASED_SIGNAL] = g_signal_new ("mouse-released",
                                                                       paned_list_get_type (),
                                                                       G_SIGNAL_RUN_LAST,
                                                                       0,
                                                                       NULL,
                                                                       NULL,
                                                                       g_cclosure_user_marshal_VOID__INT_INT,
                                                                       G_TYPE_NONE,
                                                                       2,
                                                                       G_TYPE_INT,
                                                                       G_TYPE_INT);

  paned_list_signals[PANED_LIST_ITEM_SELECTED_SIGNAL] = g_signal_new ("item-selected",
                                                                       paned_list_get_type (),
                                                                       G_SIGNAL_RUN_LAST,
                                                                       0,
                                                                       NULL,
                                                                       NULL,
                                                                       g_cclosure_marshal_VOID__STRING,
                                                                       G_TYPE_NONE,
                                                                       1,
                                                                       G_TYPE_STRING);

  paned_list_signals[PANED_LIST_LAUNCHED_SIGNAL] = g_signal_new ("launched",
                                                                  paned_list_get_type (),
                                                                  G_SIGNAL_RUN_LAST,
                                                                  0,
                                                                  NULL,
                                                                  NULL,
                                                                  g_cclosure_marshal_VOID__STRING,
                                                                  G_TYPE_NONE,
                                                                  1,
                                                                  G_TYPE_STRING);
}
