#include "desktop.h"

#include <wtypes.h>

int GetDesktopHorRes()
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);

	return desktop.right;
}

int GetDekstopVertRes()
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);

	return desktop.bottom;
}
