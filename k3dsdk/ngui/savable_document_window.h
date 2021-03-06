#ifndef K3DSDK_NGUI_SAVABLE_DOCUMENT_WINDOW_H
#define K3DSDK_NGUI_SAVABLE_DOCUMENT_WINDOW_H

// K-3D
// Copyright (c) 1995-2004, Timothy M. Shead
//
// Contact: tshead@k-3d.com
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public
// License along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

/** \file
		\author Tim Shead (tshead@k-3d.com)
*/

#include <k3dsdk/ngui/unsaved_document.h>

#include <gtkmm/window.h>

namespace k3d { class idocument; }

namespace k3d
{

namespace ngui
{

class document_state;
	
///////////////////////////////////////////////////////////////////////////////
// savable_document_window

/// Provides a standard document-level window
class savable_document_window :
        public Gtk::Window,
	public k3d::ngui::unsaved_document
{
	typedef Gtk::Window base;

public:
	savable_document_window();
	virtual ~savable_document_window();

	/// Called once after startup to complete initialization (we do this in a separate method for plugins that can't take constructor arguments).
	void initialize(document_state& Document);

	k3d::idocument& document();

	k3d::bool_t on_key_press_event(GdkEventKey* event);
	k3d::bool_t on_delete_event(GdkEventAny* event);

	/// Gives the user a chance to save changes, returns true iff all changes have been saved.
	const k3d::bool_t save_changes();
	/// Closes the window safely, giving the user a chance to save changes or cancel.
	void safe_close();
	/// Closes the window.
	void close();

private:
	k3d::ngui::unsaved_document* on_safe_close();

	/// Override in derived classes to handle cleanup when the window is closed
	virtual void on_close();

	k3d::ngui::document_state* m_document;
};

} // namespace ngui

} // namespace k3d

#endif // !K3DSDK_NGUI_SAVABLE_DOCUMENT_WINDOW_H

