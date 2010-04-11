// K-3D
// Copyright (c) 1995-2008, Timothy M. Shead
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
	\author Timothy M. Shead (tshead@k-3d.com)
*/

#include <k3dsdk/python/idocument_python.h>
#include <k3dsdk/python/irender_camera_preview_python.h>
#include <k3dsdk/python/iunknown_python.h>
#include <k3dsdk/python/utility_python.h>

#include <k3dsdk/path.h>
#include <k3dsdk/icamera.h>
#include <k3dsdk/irender_camera_preview.h>
#include <k3dsdk/iplugin_factory.h>

#include <boost/python.hpp>
using namespace boost::python;

namespace k3d 
{

namespace python
{

static bool_t render_camera_preview(iunknown_wrapper& Self, iunknown_wrapper& Camera)
{
	return Self.wrapped<k3d::irender_camera_preview>().render_camera_preview(Camera.wrapped<k3d::icamera>());
}

void define_methods_irender_camera_preview(iunknown& Interface, boost::python::object& Instance)
{
	if(!dynamic_cast<k3d::irender_camera_preview*>(&Interface))
		return;

	utility::add_method(utility::make_function(&render_camera_preview, "Renders a preview image using the given camera."), "render_camera_preview", Instance);
}

} // namespace python

} // namespace k3d

