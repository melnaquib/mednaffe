/*
 * settings_glade.h
 * 
 * Copyright 2013 AmatCoder
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
 */
 
#ifndef SETTINGS_GLADE_H
#define SETTINGS_GLADE_H

static const char *settings_glade =
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
"<interface>\n"
"<requires lib=\"gtk+\" version=\"2.18\"/>\n"
"<!-- interface-naming-policy project-wide -->\n"
"<object class=\"GtkDialog\" id=\"dialog1\">\n"
"<property name=\"can_focus\">False</property>\n"
"<property name=\"border_width\">5</property>\n"
"<property name=\"title\" translatable=\"yes\">Preferences</property>\n"
"<property name=\"modal\">True</property>\n"
"<property name=\"destroy_with_parent\">True</property>\n"
"<property name=\"type_hint\">dialog</property>\n"
"<signal name=\"delete-event\" handler=\"close_prefs\" swapped=\"no\"/>\n"
"<child internal-child=\"vbox\">\n"
"<object class=\"GtkVBox\" id=\"dialog-vbox1\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">False</property>\n"
"<property name=\"spacing\">2</property>\n"
"<child internal-child=\"action_area\">\n"
"<object class=\"GtkHButtonBox\" id=\"dialog-action_area1\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">False</property>\n"
"<property name=\"layout_style\">end</property>\n"
"<child>\n"
"<object class=\"GtkButton\" id=\"button1\">\n"
"<property name=\"label\">gtk-close</property>\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">True</property>\n"
"<property name=\"receives_default\">True</property>\n"
"<property name=\"use_stock\">True</property>\n"
"<signal name=\"clicked\" handler=\"cancel_prefs\" swapped=\"no\"/>\n"
"</object>\n"
"<packing>\n"
"<property name=\"expand\">False</property>\n"
"<property name=\"fill\">False</property>\n"
"<property name=\"position\">0</property>\n"
"</packing>\n"
"</child>\n"
"</object>\n"
"<packing>\n"
"<property name=\"expand\">True</property>\n"
"<property name=\"fill\">True</property>\n"
"<property name=\"position\">0</property>\n"
"</packing>\n"
"</child>\n"
"<child>\n"
"<object class=\"GtkNotebook\" id=\"notebook1\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">True</property>\n"
"<child>\n"
"<object class=\"GtkFrame\" id=\"frame18\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">False</property>\n"
"<property name=\"border_width\">4</property>\n"
"<property name=\"label_xalign\">0</property>\n"
"<property name=\"shadow_type\">none</property>\n"
"<child>\n"
"<object class=\"GtkAlignment\" id=\"alignment21\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">False</property>\n"
"<property name=\"left_padding\">12</property>\n"
"<child>\n"
"<object class=\"GtkVBox\" id=\"vbox28\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">False</property>\n"
"<child>\n"
"<object class=\"GtkCheckButton\" id=\"showtooltips\">\n"
"<property name=\"label\" translatable=\"yes\">Show tooltips</property>\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">True</property>\n"
"<property name=\"receives_default\">False</property>\n"
"<property name=\"has_tooltip\">True</property>\n"
"<property name=\"tooltip_text\" translatable=\"yes\">Tooltips are informative, but sometimes they can be annoying.\n"
"You can disable them here.</property>\n"
"<property name=\"active\">True</property>\n"
"<property name=\"draw_indicator\">True</property>\n"
"<signal name=\"toggled\" handler=\"on_showtooltips_toggled\" swapped=\"no\"/>\n"
"</object>\n"
"<packing>\n"
"<property name=\"expand\">False</property>\n"
"<property name=\"fill\">True</property>\n"
"<property name=\"position\">0</property>\n"
"</packing>\n"
"</child>\n"
"<child>\n"
"<object class=\"GtkCheckButton\" id=\"remembersize\">\n"
"<property name=\"label\" translatable=\"yes\">Remember window size</property>\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">True</property>\n"
"<property name=\"receives_default\">False</property>\n"
"<property name=\"active\">True</property>\n"
"<property name=\"draw_indicator\">True</property>\n"
"</object>\n"
"<packing>\n"
"<property name=\"expand\">False</property>\n"
"<property name=\"fill\">True</property>\n"
"<property name=\"position\">1</property>\n"
"</packing>\n"
"</child>\n"
"<child>\n"
"<object class=\"GtkVBox\" id=\"vbox26\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">False</property>\n"
"<child>\n"
"<object class=\"GtkLabel\" id=\"label71\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">False</property>\n"
"<property name=\"xalign\">0</property>\n"
"<property name=\"label\" translatable=\"yes\">Action when launch:</property>\n"
"</object>\n"
"<packing>\n"
"<property name=\"expand\">False</property>\n"
"<property name=\"fill\">True</property>\n"
"<property name=\"padding\">3</property>\n"
"<property name=\"position\">0</property>\n"
"</packing>\n"
"</child>\n"
"<child>\n"
"<object class=\"GtkAlignment\" id=\"alignment20\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">False</property>\n"
"<property name=\"left_padding\">12</property>\n"
"<child>\n"
"<object class=\"GtkVBox\" id=\"vbox27\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">False</property>\n"
"<child>\n"
"<object class=\"GtkRadioButton\" id=\"rbnothing\">\n"
"<property name=\"label\" translatable=\"yes\">Do nothing</property>\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">True</property>\n"
"<property name=\"receives_default\">False</property>\n"
"<property name=\"active\">True</property>\n"
"<property name=\"draw_indicator\">True</property>\n"
"<signal name=\"clicked\" handler=\"on_rbnothing_activate\" swapped=\"no\"/>\n"
"</object>\n"
"<packing>\n"
"<property name=\"expand\">False</property>\n"
"<property name=\"fill\">True</property>\n"
"<property name=\"position\">0</property>\n"
"</packing>\n"
"</child>\n"
"<child>\n"
"<object class=\"GtkRadioButton\" id=\"rbminimize\">\n"
"<property name=\"label\" translatable=\"yes\">Minimize</property>\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">True</property>\n"
"<property name=\"receives_default\">False</property>\n"
"<property name=\"draw_indicator\">True</property>\n"
"<property name=\"group\">rbnothing</property>\n"
"<signal name=\"clicked\" handler=\"on_rbminimize_activate\" swapped=\"no\"/>\n"
"</object>\n"
"<packing>\n"
"<property name=\"expand\">False</property>\n"
"<property name=\"fill\">True</property>\n"
"<property name=\"position\">1</property>\n"
"</packing>\n"
"</child>\n"
"<child>\n"
"<object class=\"GtkRadioButton\" id=\"rbhide\">\n"
"<property name=\"label\" translatable=\"yes\">Hide</property>\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">True</property>\n"
"<property name=\"receives_default\">False</property>\n"
"<property name=\"draw_indicator\">True</property>\n"
"<property name=\"group\">rbminimize</property>\n"
"<signal name=\"clicked\" handler=\"on_rbhide_activate\" swapped=\"no\"/>\n"
"</object>\n"
"<packing>\n"
"<property name=\"expand\">False</property>\n"
"<property name=\"fill\">True</property>\n"
"<property name=\"position\">2</property>\n"
"</packing>\n"
"</child>\n"
"</object>\n"
"</child>\n"
"</object>\n"
"<packing>\n"
"<property name=\"expand\">False</property>\n"
"<property name=\"fill\">True</property>\n"
"<property name=\"position\">2</property>\n"
"</packing>\n"
"</child>\n"
"</object>\n"
"<packing>\n"
"<property name=\"expand\">False</property>\n"
"<property name=\"fill\">True</property>\n"
"<property name=\"padding\">12</property>\n"
"<property name=\"position\">2</property>\n"
"</packing>\n"
"</child>\n"
"</object>\n"
"</child>\n"
"</object>\n"
"</child>\n"
"<child type=\"label\">\n"
"<object class=\"GtkLabel\" id=\"label73\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">False</property>\n"
"<property name=\"label\" translatable=\"yes\">&lt;b&gt;Options&lt;/b&gt;</property>\n"
"<property name=\"use_markup\">True</property>\n"
"</object>\n"
"</child>\n"
"</object>\n"
"</child>\n"
"<child type=\"tab\">\n"
"<object class=\"GtkLabel\" id=\"label1\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">False</property>\n"
"<property name=\"label\" translatable=\"yes\">General</property>\n"
"</object>\n"
"<packing>\n"
"<property name=\"tab_fill\">False</property>\n"
"</packing>\n"
"</child>\n"
"<child>\n"
"<object class=\"GtkFrame\" id=\"frame1\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">False</property>\n"
"<property name=\"border_width\">4</property>\n"
"<property name=\"label_xalign\">0</property>\n"
"<property name=\"shadow_type\">none</property>\n"
"<child>\n"
"<object class=\"GtkAlignment\" id=\"alignment1\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">False</property>\n"
"<property name=\"top_padding\">12</property>\n"
"<property name=\"left_padding\">12</property>\n"
"<child>\n"
"<object class=\"GtkTreeView\" id=\"treeview1\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">True</property>\n"
"<property name=\"model\">liststore1</property>\n"
"<property name=\"headers_clickable\">False</property>\n"
"<property name=\"enable_search\">False</property>\n"
"<child>\n"
"<object class=\"GtkTreeViewColumn\" id=\"treeviewcolumn1\">\n"
"<property name=\"title\" translatable=\"yes\">Systems</property>\n"
"<child>\n"
"<object class=\"GtkCellRendererText\" id=\"cellrenderertext1\"/>\n"
"<attributes>\n"
"<attribute name=\"text\">0</attribute>\n"
"</attributes>\n"
"</child>\n"
"</object>\n"
"</child>\n"
"</object>\n"
"</child>\n"
"</object>\n"
"</child>\n"
"<child type=\"label\">\n"
"<object class=\"GtkLabel\" id=\"label5\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">False</property>\n"
"<property name=\"label\" translatable=\"yes\">&lt;b&gt;Show In List&lt;/b&gt;</property>\n"
"<property name=\"use_markup\">True</property>\n"
"</object>\n"
"</child>\n"
"</object>\n"
"<packing>\n"
"<property name=\"position\">1</property>\n"
"</packing>\n"
"</child>\n"
"<child type=\"tab\">\n"
"<object class=\"GtkLabel\" id=\"label2\">\n"
"<property name=\"visible\">True</property>\n"
"<property name=\"can_focus\">False</property>\n"
"<property name=\"label\" translatable=\"yes\">Systems</property>\n"
"</object>\n"
"<packing>\n"
"<property name=\"position\">1</property>\n"
"<property name=\"tab_fill\">False</property>\n"
"</packing>\n"
"</child>\n"
"</object>\n"
"<packing>\n"
"<property name=\"expand\">True</property>\n"
"<property name=\"fill\">True</property>\n"
"<property name=\"position\">1</property>\n"
"</packing>\n"
"</child>\n"
"</object>\n"
"</child>\n"
"<action-widgets>\n"
"<action-widget response=\"0\">button1</action-widget>\n"
"</action-widgets>\n"
"</object>\n"
"<object class=\"GtkListStore\" id=\"liststore1\">\n"
"<columns>\n"
"<!-- column-name System -->\n"
"<column type=\"gchararray\"/>\n"
"<!-- column-name Show -->\n"
"<column type=\"gboolean\"/>\n"
"<!-- column-name gint1 -->\n"
"<column type=\"gint\"/>\n"
"</columns>\n"
"<data>\n"
"<row>\n"
"<col id=\"0\">Atary Lynx</col>\n"
"<col id=\"1\">True</col>\n"
"<col id=\"2\">0</col>\n"
"</row>\n"
"<row>\n"
"<col id=\"0\">GameBoy (Color)</col>\n"
"<col id=\"1\">True</col>\n"
"<col id=\"2\">1</col>\n"
"</row>\n"
"<row>\n"
"<col id=\"0\">GameBoy Advance</col>\n"
"<col id=\"1\">True</col>\n"
"<col id=\"2\">2</col>\n"
"</row>\n"
"<row>\n"
"<col id=\"0\">Neo Geo Pocket (Color)</col>\n"
"<col id=\"1\">True</col>\n"
"<col id=\"2\">3</col>\n"
"</row>\n"
"<row>\n"
"<col id=\"0\">Nintendo Entertainment System/Famicom</col>\n"
"<col id=\"1\">True</col>\n"
"<col id=\"2\">4</col>\n"
"</row>\n"
"<row>\n"
"<col id=\"0\">PC Engine (CD)/TurboGrafx 16 (CD)/SuperGrafx</col>\n"
"<col id=\"1\">True</col>\n"
"<col id=\"2\">5</col>\n"
"</row>\n"
"<row>\n"
"<col id=\"0\">PC-FX</col>\n"
"<col id=\"1\">True</col>\n"
"<col id=\"2\">6</col>\n"
"</row>\n"
"<row>\n"
"<col id=\"0\">Sega Game Gear</col>\n"
"<col id=\"1\">True</col>\n"
"<col id=\"2\">7</col>\n"
"</row>\n"
"<row>\n"
"<col id=\"0\">Sega Genesis/MegaDrive</col>\n"
"<col id=\"1\">True</col>\n"
"<col id=\"2\">8</col>\n"
"</row>\n"
"<row>\n"
"<col id=\"0\">Sega Master System</col>\n"
"<col id=\"1\">True</col>\n"
"<col id=\"2\">9</col>\n"
"</row>\n"
"<row>\n"
"<col id=\"0\">Sony PlayStation</col>\n"
"<col id=\"1\">True</col>\n"
"<col id=\"2\">10</col>\n"
"</row>\n"
"<row>\n"
"<col id=\"0\">Super Nintendo Entertainment System/Super Famicom</col>\n"
"<col id=\"1\">True</col>\n"
"<col id=\"2\">11</col>\n"
"</row>\n"
"<row>\n"
"<col id=\"0\">Virtual Boy</col>\n"
"<col id=\"1\">True</col>\n"
"<col id=\"2\">12</col>\n"
"</row>\n"
"<row>\n"
"<col id=\"0\">WonderSwan (Color)</col>\n"
"<col id=\"1\">True</col>\n"
"<col id=\"2\">13</col>\n"
"</row>\n"
"</data>\n"
"</object>\n"
"</interface>\n"
;

#endif /* SETTINGS_GLADE_H */
