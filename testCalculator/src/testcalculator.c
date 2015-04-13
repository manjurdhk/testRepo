/*
 * Copyright (c) 2013 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <tizen.h>
#include "testcalculator.h"

typedef struct appdata {
	const char *name;
	Evas_Object *win;
	Evas_Object *bg;
	Evas_Object *conform;
	Evas_Object *entry;
	Evas_Object *basic_content;
	Evas_Object *advanced_content;
} appdata_s;

static void
win_delete_request_cb(void *data , Evas_Object *obj , void *event_info)
{
	ui_app_exit();
}

static void
win_back_cb(void *data , Evas_Object *obj , void *event)
{
	appdata_s *ad = data;
	/* Let window go to hide state. */
	elm_win_lower(ad->win);
}

static Evas_Object *
create_bg(Evas_Object *parent)
{
	Evas_Object *bg;

	if (parent == NULL) return NULL;

	bg = elm_bg_add(parent);
	evas_object_size_hint_weight_set(bg, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	elm_win_resize_object_add(parent, bg);
	evas_object_show(bg);

	return bg;
}

static Evas_Object *
create_conform(Evas_Object *parent)
{
	Evas_Object *conform, *bg;

	if (parent == NULL) return NULL;

	conform = elm_conformant_add(parent);
	evas_object_size_hint_weight_set(conform, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	elm_win_resize_object_add(parent, conform);

	bg = elm_bg_add(conform);
	elm_object_style_set(bg, "indicator/headerbg");
	elm_object_part_content_set(conform, "elm.swallow.indicator_bg", bg);
	evas_object_show(bg);

	evas_object_show(conform);
	return conform;
}

static void
rotation_cb(void *data, Evas_Object *obj, void *event_info)
{
	appdata_s *ad = data;
	int current_degree = elm_win_rotation_get(obj);

	if (current_degree != 0 && current_degree != 180) {
		elm_grid_pack_set(ad->basic_content, 45, 3, 52, 94);
		elm_grid_pack_set(ad->advanced_content, 3, 3, 36, 94);
	} else {
		elm_grid_pack_set(ad->basic_content, 3, 3, 94, 94);
		elm_grid_pack_set(ad->advanced_content, -100, -100, 94, 94);
	}
}

static void
clicked_0_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *entry = data;
   elm_entry_entry_append(entry, "<font_size=50>0</font_size>");
}

static void
clicked_1_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *entry = data;
   elm_entry_entry_append(entry, "<font_size=50>1</font_size>");
}

static void
clicked_2_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *entry = data;
   elm_entry_entry_append(entry, "<font_size=50>2</font_size>");
}

static void
clicked_3_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *entry = data;
   elm_entry_entry_append(entry, "<font_size=50>3</font_size>");
}

static void
clicked_4_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *entry = data;
   elm_entry_entry_append(entry, "<font_size=50>4</font_size>");
}

static void
clicked_5_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *entry = data;
   elm_entry_entry_append(entry, "<font_size=50>5</font_size>");
}

static void
clicked_6_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *entry = data;
   elm_entry_entry_append(entry, "<font_size=50>6</font_size>");
}

static void
clicked_7_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *entry = data;
   elm_entry_entry_append(entry, "<font_size=50>7</font_size>");
}

static void
clicked_8_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *entry = data;
   elm_entry_entry_append(entry, "<font_size=50>8</font_size>");
}

static void
clicked_9_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *entry = data;
   elm_entry_entry_append(entry, "<font_size=50>9</font_size>");
}

static void
clicked_c_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *entry = data;
   elm_entry_entry_set(entry, "<align=right>");
}

static void
clicked_divide_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *entry = data;
   elm_entry_entry_append(entry, "<font_size=50>/</font_size>");
}

static void
clicked_multi_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *entry = data;
   elm_entry_entry_append(entry, "<font_size=50>X</font_size>");
}

static void
clicked_plus_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *entry = data;
   elm_entry_entry_append(entry, "<font_size=50>+</font_size>");
}

static void
clicked_minus_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *entry = data;
   elm_entry_entry_append(entry, "<font_size=50>-</font_size>");
}

static void
clicked_dot_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *entry = data;
   elm_entry_entry_append(entry, "<font_size=50>.</font_size>");
}

static Evas_Object *
create_panel_basic_content(Evas_Object *parent, appdata_s *ad)
{
	Evas_Object *table, *button;

	table = elm_table_add(parent);
	elm_table_padding_set(table, 10, 10);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>C</font_size>");
	evas_object_smart_callback_add(button, "clicked", clicked_c_cb, ad->entry);
	evas_object_show(button);
	elm_table_pack(table, button, 0, 0, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>/</font_size>");
	evas_object_smart_callback_add(button, "clicked", clicked_divide_cb, ad->entry);
	evas_object_show(button);
	elm_table_pack(table, button, 1, 0, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>X</font_size>");
	evas_object_smart_callback_add(button, "clicked", clicked_multi_cb, ad->entry);
	evas_object_show(button);
	elm_table_pack(table, button, 2, 0, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>Back</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 3, 0, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>7</font_size>");
	evas_object_smart_callback_add(button, "clicked", clicked_7_cb, ad->entry);
	evas_object_show(button);
	elm_table_pack(table, button, 0, 1, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>8</font_size>");
	evas_object_smart_callback_add(button, "clicked", clicked_8_cb, ad->entry);
	evas_object_show(button);
	elm_table_pack(table, button, 1, 1, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>9</font_size>");
	evas_object_smart_callback_add(button, "clicked", clicked_9_cb, ad->entry);
	evas_object_show(button);
	elm_table_pack(table, button, 2, 1, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>-</font_size>");
	evas_object_smart_callback_add(button, "clicked", clicked_minus_cb, ad->entry);
	evas_object_show(button);
	elm_table_pack(table, button, 3, 1, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>4</font_size>");
	evas_object_smart_callback_add(button, "clicked", clicked_4_cb, ad->entry);
	evas_object_show(button);
	elm_table_pack(table, button, 0, 2, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>5</font_size>");
	evas_object_smart_callback_add(button, "clicked", clicked_5_cb, ad->entry);
	evas_object_show(button);
	elm_table_pack(table, button, 1, 2, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>6</font_size>");
	evas_object_smart_callback_add(button, "clicked", clicked_6_cb, ad->entry);
	evas_object_show(button);
	elm_table_pack(table, button, 2, 2, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>+</font_size>");
	evas_object_smart_callback_add(button, "clicked", clicked_plus_cb, ad->entry);
	evas_object_show(button);
	elm_table_pack(table, button, 3, 2, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>1</font_size>");
	evas_object_smart_callback_add(button, "clicked", clicked_1_cb, ad->entry);
	evas_object_show(button);
	elm_table_pack(table, button, 0, 3, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>2</font_size>");
	evas_object_smart_callback_add(button, "clicked", clicked_2_cb, ad->entry);
	evas_object_show(button);
	elm_table_pack(table, button, 1, 3, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>3</font_size>");
	evas_object_smart_callback_add(button, "clicked", clicked_3_cb, ad->entry);
	evas_object_show(button);
	elm_table_pack(table, button, 2, 3, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>( )</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 3, 3, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>0</font_size>");
	evas_object_smart_callback_add(button, "clicked", clicked_0_cb, ad->entry);
	evas_object_show(button);
	elm_table_pack(table, button, 0, 4, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>.</font_size>");
	evas_object_smart_callback_add(button, "clicked", clicked_dot_cb, ad->entry);
	evas_object_show(button);
	elm_table_pack(table, button, 1, 4, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>+/-</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 2, 4, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>=</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 3, 4, 1, 1);

	evas_object_show(table);

	return table;
}

static Evas_Object *
create_panel_advanced_content(Evas_Object *parent, appdata_s *ad)
{
	Evas_Object *table, *button;

	table = elm_table_add(parent);
	elm_table_padding_set(table, 10, 10);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>x!</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 0, 0, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>sqrt</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 1, 0, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>%</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 2, 0, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>sin</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 0, 1, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>cos</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 1, 1, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>tan</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 2, 1, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>ln</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 0, 2, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>log</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 1, 2, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>1/x</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 2, 2, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>e^x</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 0, 3, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>X^2</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 1, 3, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>Y^x</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 2, 3, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>| X |</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 0, 4, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>PI</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 1, 4, 1, 1);

	button = elm_button_add(table);
	evas_object_size_hint_weight_set(button, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_text_set(button, "<font_size = 50>e</font_size>");
	evas_object_show(button);
	elm_table_pack(table, button, 2, 4, 1, 1);

	evas_object_show(table);

	return table;
}

static Evas_Object *
create_panel(Evas_Object *parent, appdata_s *ad)
{
	Evas_Object *panel, *grid;

	/* Panel */
	panel = elm_panel_add(parent);
	elm_panel_orient_set(panel, ELM_PANEL_ORIENT_BOTTOM);
	evas_object_show(panel);

	/* Grid */
	grid = elm_grid_add(panel);
	evas_object_size_hint_weight_set(grid, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(grid, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_content_set(panel, grid);

	/* Panel basic content */
	ad->basic_content = create_panel_basic_content(grid, ad);
	evas_object_size_hint_weight_set(ad->basic_content, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(ad->basic_content, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_grid_pack(grid, ad->basic_content, 3, 3, 94, 94);

	/* Panel advanced content */
	ad->advanced_content = create_panel_advanced_content(grid, ad);
	evas_object_size_hint_weight_set(ad->advanced_content, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(ad->advanced_content, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_grid_pack(grid, ad->advanced_content, -100, -100, 94, 94);

	return panel;
}

static Evas_Object *
create_entry(Evas_Object *parent)
{
	Evas_Object *entry;

	entry = elm_entry_add(parent);
	elm_entry_editable_set(entry, EINA_FALSE);
	elm_entry_entry_set(entry, "<font_size=50><align=right></font_size>");
	evas_object_show(entry);

	return entry;
}

static void
create_base_gui(appdata_s *ad)
{
	Evas_Object *grid, *panel;

	ad->win = elm_win_util_standard_add(PACKAGE, PACKAGE);
	elm_win_autodel_set(ad->win, EINA_TRUE);

	if (elm_win_wm_rotation_supported_get(ad->win)) {
		int rots[4] = { 0, 90, 180, 270 };
		elm_win_wm_rotation_available_rotations_set(ad->win, (const int *)(&rots), 4);
	}

	evas_object_smart_callback_add(ad->win, "wm,rotation,changed", rotation_cb, ad);
	evas_object_smart_callback_add(ad->win, "delete,request", win_delete_request_cb, NULL);
	eext_object_event_callback_add(ad->win, EEXT_CALLBACK_BACK, win_back_cb, ad);

	ad->bg = create_bg(ad->win);
	ad->conform = create_conform(ad->win);
	elm_win_conformant_set(ad->win, EINA_TRUE);
	elm_win_indicator_mode_set(ad->win, ELM_WIN_INDICATOR_SHOW);
	elm_win_indicator_opacity_set(ad->win, ELM_WIN_INDICATOR_OPAQUE);

	/* Grid */
	grid = elm_grid_add(ad->conform);
	evas_object_size_hint_weight_set(grid, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(grid, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_content_set(ad->conform, grid);

	/* Entry */
	ad->entry = create_entry(grid);
	elm_grid_pack(grid, ad->entry, 5, 5, 90, 25);

	/* Panel */
	panel = create_panel(grid, ad);
	elm_grid_pack(grid, panel, 0, 35, 100, 65);

	/* Show window after base gui is set up */
	evas_object_show(ad->win);
}

static bool
app_create(void *data)
{
	/* Hook to take necessary actions before main event loop starts
		Initialize UI resources and application's data
		If this function returns true, the main loop of application starts
		If this function returns false, the application is terminated */
	appdata_s *ad = data;

	create_base_gui(ad);

	return true;
}

static void
app_control(app_control_h app_control, void *data)
{
	/* Handle the launch request. */
}

static void
app_pause(void *data)
{
	/* Take necessary actions when application becomes invisible. */
}

static void
app_resume(void *data)
{
	/* Take necessary actions when application becomes visible. */
}

static void
app_terminate(void *user_data)
{
    /* Release all resources (*/
	appdata_s *ad;

	if (!user_data)
		return;

	ad = user_data;

	if (ad->win)
		evas_object_del(ad->win);
}

static void
ui_app_lang_changed(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_LANGUAGE_CHANGED*/
	char *locale = NULL;
	system_settings_get_value_string(SYSTEM_SETTINGS_KEY_LOCALE_LANGUAGE, &locale);
	elm_language_set(locale);
	free(locale);
	return;
}

static void
ui_app_orient_changed(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_DEVICE_ORIENTATION_CHANGED*/
	return;
}

static void
ui_app_region_changed(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_REGION_FORMAT_CHANGED*/
}

static void
ui_app_low_battery(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_LOW_BATTERY*/
}

static void
ui_app_low_memory(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_LOW_MEMORY*/
}

int main(int argc, char *argv[])
{
	appdata_s ad = {0,};
	int ret = 0;

	ui_app_lifecycle_callback_s event_callback = {0,};
	app_event_handler_h handlers[5] = {NULL, };

	event_callback.create = app_create;
	event_callback.terminate = app_terminate;
	event_callback.pause = app_pause;
	event_callback.resume = app_resume;
	event_callback.app_control = app_control;

	ui_app_add_event_handler(&handlers[APP_EVENT_LOW_BATTERY], APP_EVENT_LOW_BATTERY, ui_app_low_battery, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_LOW_MEMORY], APP_EVENT_LOW_MEMORY, ui_app_low_memory, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_DEVICE_ORIENTATION_CHANGED], APP_EVENT_DEVICE_ORIENTATION_CHANGED, ui_app_orient_changed, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_LANGUAGE_CHANGED], APP_EVENT_LANGUAGE_CHANGED, ui_app_lang_changed, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_REGION_FORMAT_CHANGED], APP_EVENT_REGION_FORMAT_CHANGED, ui_app_region_changed, &ad);
	ui_app_remove_event_handler(handlers[APP_EVENT_LOW_MEMORY]);

	ret = ui_app_main(argc, argv, &event_callback, &ad);
	if (ret != APP_ERROR_NONE) {
		dlog_print(DLOG_ERROR, LOG_TAG, "ui_app_main() is failed. err = %d", ret);
	}

	return ret;
}
