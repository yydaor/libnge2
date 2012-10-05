/*
** Haaf's Game Engine 1.7
** Copyright (C) 2003-2007, Relish Games
** hge.relishgames.com
**
** hgeDistortionMesh helper class header
*/


#ifndef HGEDISTORT_H
#define HGEDISTORT_H


#include "nge_common.h"

#define HGEDISP_NODE		0
#define HGEDISP_TOPLEFT		1
#define HGEDISP_CENTER		2

struct hgeQuad
{
	hgeVertex		v[4];
	image_p			tex;
	int				blend;
};

/*
** HGE Distortion mesh class
*/
class hgeDistortionMesh
{
public:
     hgeDistortionMesh(int cols, int rows);
     hgeDistortionMesh(const hgeDistortionMesh &dm);
     ~hgeDistortionMesh();

	 hgeDistortionMesh&	operator= (const hgeDistortionMesh &dm);

     void		Render(float x, float y);
     void		Clear(uint32_t col=0xFFFFFFFF, float z=0.5f);

     void		SetTexture(image_p tex);
     void		SetTextureRect(float x, float y, float w, float h);
     void		SetBlendMode(int blend);
     void		SetZ(int col, int row, float z);
     void		SetColor(int col, int row, uint32_t color);
     void		SetDisplacement(int col, int row, float dx, float dy, int ref);

     HTEXTURE	GetTexture() const {return quad.tex;}
     void		GetTextureRect(float *x, float *y, float *w, float *h) const { *x=tx; *y=ty; *w=width; *h=height; }
     int		GetBlendMode() const { return quad.blend; }
     float		GetZ(int col, int row) const;
     uint32_t		GetColor(int col, int row) const;
     void		GetDisplacement(int col, int row, float *dx, float *dy, int ref) const;

	 int		GetRows() { return nRows; }
	 int		GetCols() { return nCols; }

private:
	hgeDistortionMesh();

	hgeVertex	*disp_array;
	int			nRows, nCols;
	float		cellw,cellh;
	float		tx,ty,width,height;
	hgeQuad		quad;
};


#endif
