INCLUDE_DIRECTORIES(${K3D_OPENEXR_INCLUDE_DIRS})
LINK_DIRECTORIES(${K3D_OPENEXR_LIB_DIRS})

K3D_BUILD_MODULE(k3d-openexr-io)
K3D_CREATE_MODULE_PROXY(k3d-openexr-io)

TARGET_LINK_LIBRARIES(k3d-openexr-io ${K3D_OPENEXR_LIBS})

