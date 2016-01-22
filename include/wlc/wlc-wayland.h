#ifndef _WLC_WAYLAND_H_
#define _WLC_WAYLAND_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <wlc/defines.h>
#include <wlc/geometry.h>
#include <wayland-server.h>

typedef uintptr_t wlc_resource;

struct wl_resource;
struct wl_display;

/** Returns Wayland display. */
struct wl_display* wlc_get_wl_display(void);

/** Returns view handle from wl_surface resource. */
WLC_NONULL wlc_handle wlc_handle_from_wl_surface_resource(struct wl_resource *resource);

/** Returns output handle from wl_output resource. */
WLC_NONULL wlc_handle wlc_handle_from_wl_output_resource(struct wl_resource *resource);

/** Returns internal wlc surface from wl_surface resource. */
WLC_NONULL wlc_resource wlc_resource_from_wl_surface_resource(struct wl_resource *resource);

/** Get surface size. */
const struct wlc_size* wlc_surface_get_size(wlc_resource surface);

/** Return wl_surface resource from internal wlc surface. */
struct wl_resource* wlc_surface_get_wl_resource(wlc_resource surface);

/** Function for rendering surfaces inside post / pre render hooks. */
WLC_NONULL void wlc_surface_render(wlc_resource surface, const struct wlc_geometry *geometry);

/** Turns wl_surface into a wlc view. Returns 0 on failure. This will also trigger view.created callback as any view would. */
wlc_handle wlc_view_from_surface(wlc_resource surface, struct wl_client *client, const struct wl_interface *interface, const void *implementation);

/** Returns internal wlc surface from view handle */
wlc_resource wlc_view_get_surface(wlc_handle view);

/** Returns surface role resource from view handle. Return value will be NULL if the view was not assigned role or created with wlc_view_create_from_surface(). */
struct wl_resource* wlc_view_get_role(wlc_handle view);

#ifdef __cplusplus
}
#endif

#endif /* _WLC_WAYLAND_H_ */