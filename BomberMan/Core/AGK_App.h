#ifndef _H_AGK_APP_
#define _H_AGK_APP_

#define	ConnectApplication(agk_app)						_g_agk_app = agk_app
#define	SetupDevice(width, height, fullscreen)			_g_agk_device_width = width; \
														_g_agk_device_height = height; \
														_g_agk_device_fullscreen = fullscreen
#define SetupTitle(string)								_g_agk_title = string

class AGK_App
{
public:
	// constructor / destructor
	AGK_App() {}
	~AGK_App() {}

	// main app functions - mike to experiment with a derived class for this..
	virtual void Begin(void) = 0L;
	virtual void Loop(void) = 0L;
	virtual void End(void) = 0L;
};

extern AGK_App*		_g_agk_app;
extern int			_g_agk_device_width;
extern int			_g_agk_device_height;
extern bool			_g_agk_device_fullscreen;
extern char*		_g_agk_title;

#endif
