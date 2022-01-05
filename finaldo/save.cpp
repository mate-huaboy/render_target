#include <windows.h>
#include <gl/GL.h>

#include <CommCtrl.h>
#include <commdlg.h>
#include <comdef.h>
#include <GdiPlus.h>
#include <vcruntime_string.h>
#include <cstdio>
#include <minwindef.h>

#include <stdlib.h>
#include <wingdi.h>
#include<FreeImage.h>


bool SaveImage(const char* imgpath, int w, int h)
{
	/*
	int img_widht,img_height;
	unsigned char *mpixels =new unsigned char[1024*768*4];
	FREE_IMAGE_FORMAT fif =FIF_PNG;
	BOOL bSuccess = FALSE;

	glReadBuffer(GL_FRONT);
	glReadPixels(0, 0, 1024, 768, GL_RGBA, GL_UNSIGNED_BYTE, mpixels);
	glReadBuffer(GL_BACK);
	for(int i=0; i<(int)1024*768*4; i+=4)
	{
		//repeated xor to swap bytes
		mpixels[i] ^= mpixels[i+2] ^= mpixels[i] ^= mpixels[i+2];
	}
	FIBITMAP* bitmap = FreeImage_ConvertFromRawBits(mpixels,1024,768,4096,32,8,8,8,FALSE);
	//FIBITMAP *dibsave = FreeImage_Load(FIF_PNG,"img/default.png", 0);
	//FIBITMAP *dibsave =FreeImage_Allocate(FIF_PNG,800,800,32);
	//img_widht=FreeImage_GetWidth(dibsave);
	//img_height=FreeImage_GetHeight(dibsave);


	bSuccess = FreeImage_Save(FIF_PNG, bitmap, "gg1.png", PNG_DEFAULT);
	 FreeImage_Unload(bitmap);
	 delete[] mpixels;*/
	unsigned char* mpixels = new unsigned char[w * h * 4];
	glReadBuffer(GL_FRONT);
	glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, mpixels);
	glReadBuffer(GL_BACK);
	for (int i = 0; i < (int)w * h * 4; i += 4)
	{

		mpixels[i] ^= mpixels[i + 2] ^= mpixels[i] ^= mpixels[i + 2];
	}
	FIBITMAP* bitmap = FreeImage_Allocate(w, h, 32, 8, 8, 8);

	for (int y = 0; y < FreeImage_GetHeight(bitmap); y++)
	{
		BYTE* bits = FreeImage_GetScanLine(bitmap, y);
		for (int x = 0; x < FreeImage_GetWidth(bitmap); x++)
		{
			bits[0] = mpixels[(y * w + x) * 4 + 0];
			bits[1] = mpixels[(y * w + x) * 4 + 1];
			bits[2] = mpixels[(y * w + x) * 4 + 2];
			bits[3] = 255;
			bits += 4;

			if (x > 1600)
			{
				byte t1, t2, t3, t4;
				t1 = mpixels[(y * w + x) * 4 + 0];
				t2 = mpixels[(y * w + x) * 4 + 1];
				t3 = mpixels[(y * w + x) * 4 + 2];
			}


		}

	}
	bool bSuccess = FreeImage_Save(FIF_PNG, bitmap, imgpath, PNG_DEFAULT);
	FreeImage_Unload(bitmap);

	return bSuccess;

}