/*
 * Cairo Background renderer
 * Render all those things not supported as Image, with Cairo
 *
 * Copyright (C) 2012 Lu Wang <coolwanglu@gmail.com>
 */


#ifndef CAIRO_BACKGROUND_RENDERER_H__
#define CAIRO_BACKGROUND_RENDERER_H__

#include <CairoOutputDev/CairoOutputDev.h>
#include <cairo.h>
#include <cairo-svg.h>

#include "pdf2htmlEX-config.h"

#include "Param.h"
#include "HTMLRenderer/HTMLRenderer.h"

namespace pdf2htmlEX {

// Based on BackgroundRenderer from poppler
class CairoBackgroundRenderer : public CairoOutputDev 
{
public:
  CairoBackgroundRenderer(HTMLRenderer * html_renderer, const Param & param)
      : CairoOutputDev()
      , html_renderer(html_renderer)
      , param(param)
      , surface(nullptr)
  { }

  virtual ~CairoBackgroundRenderer() { }

  virtual void drawChar(GfxState *state, double x, double y,
      double dx, double dy,
      double originX, double originY,
      CharCode code, int nBytes, Unicode *u, int uLen);

  void render_page(PDFDoc * doc, int pageno);
  void embed_image(int pageno);

protected:
  HTMLRenderer * html_renderer;
  const Param & param;
  cairo_surface_t * surface;
};

}

#endif //CAIRO_BACKGROUND_RENDERER_H__
