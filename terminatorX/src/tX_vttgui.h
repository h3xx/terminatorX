/*
    terminatorX - realtime audio scratching software
    Copyright (C) 1999-2002  Alexander K�nig
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
 
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 
    File: tX_vttgui.h
 
    Description: Header to tX_vttgui.cc
*/    

#ifndef _h_tX_vttgui
#define _h_tX_vttgui

#include <gtk/gtk.h>
#include <config.h>
#include "tX_types.h"
#include "tX_extdial.h"
#include "tX_panel.h"
#include <list>
#include "tX_seqpar.h"


#ifdef DONT_USE_FLASH
#undef USE_FLASH
#else
#define USE_FLASH 1
#endif

typedef struct vtt_gui
{
	GtkWidget *control_box;
	GtkWidget *audio_box;

	/* Control Box Widgets */
	GtkWidget *control_label;
	GtkWidget *control_minimize;
	GtkWidget *scrolled_win;
	GtkWidget *control_subbox;
	GtkWidget *ladspa_menu;
	GtkWidget *par_menu;

	/* Main */
	tX_panel  *main_panel;
	GtkWidget *name;
	GtkWidget *show_audio;
	GtkWidget *del;
	GtkWidget *fx_button;
	
	/* Trigger */
	tX_panel  *trigger_panel;
	GtkWidget *trigger;
	GtkWidget *stop;
	GtkWidget *autotrigger;
	GtkWidget *loop;
	GtkWidget *sync_master;
	GtkWidget *sync_client;
	GtkAdjustment *cycles;
	
	/* Output Panel */
	tX_extdial *pitchd;
	tX_extdial *pand;
	GtkAdjustment *pitch;
	GtkAdjustment *pan;
	GtkAdjustment *volume; 
    GtkWidget *mute;
    GtkWidget *solo;
	GtkWidget *flash;

	/* Widgets in Lowpass Panel */
	tX_panel *lp_panel;
	GtkWidget *lp_enable;
	tX_extdial *lp_gaind;
	tX_extdial *lp_resod;
	tX_extdial *lp_freqd;
	GtkAdjustment *lp_gain;
	GtkAdjustment *lp_reso;
	GtkAdjustment *lp_freq;
	
	/* Widgets in Echo Panel */
	tX_panel *ec_panel;
	GtkWidget *ec_enable;
	tX_extdial *ec_lengthd;
	tX_extdial *ec_feedbackd;
	tX_extdial *ec_pand;
	tX_extdial *ec_volumed;
	GtkAdjustment *ec_length;
	GtkAdjustment *ec_feedback;
	GtkAdjustment *ec_pan;
	GtkAdjustment *ec_volume;

	GdkWindow *file_dialog;
	GtkWidget *fs;
	
	int32_t current_gui;

	/* Audio Box Widgets */
	GtkWidget *audio_label;
	GtkWidget *audio_minimize;
	GtkWidget *display;
	GtkWidget *file;
	GtkWidget *file_menu;

	GtkWidget *mouse_mapping;
	GtkWidget *mouse_mapping_menu;
	GtkWidget *mouse_mapping_menu_x;
	GtkWidget *mouse_mapping_menu_y;
	
	GtkWidget *audio_minimized_panel_bar_button;
	GtkWidget *control_minimized_panel_bar_button;

	GtkWidget *audio_minimized_panel_bar_label;
	GtkWidget *control_minimized_panel_bar_label;
};

extern void cleanup_all_vtts();
extern void update_all_vtts();
extern void vg_enable_critical_buttons(int enable);
extern void vg_init_all_non_seqpars();
#endif