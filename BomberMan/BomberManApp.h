#ifndef _H_SPACESHOOTER_APP_
#define _H_SPACESHOOTER_APP_


//#include	<memory.h>
#include	"Core/AGK_App.h"

#define	TITLE							"BomberMan"
#define DEVICE_WIDTH					800
#define DEVICE_HEIGHT					600
#define FULLSCREEN						false

// Global values for the app
class CBomberManApp : public AGK_App
{
public:
	// constructor
	CBomberManApp();
	~CBomberManApp() {}

	// main app functions - mike to experiment with a derived class for this..
	void Begin(void);
	void Loop(void);
	void End(void);

protected:
};

#endif

// Allow us to use the LoadImage function name
//#ifdef LoadImage
//#undef LoadImage
//#endif