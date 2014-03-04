#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class FrownParticleSystemApp : public AppNative {
  public:
    void prepareSettings(Settings* settings);
	void setup();
    void keyDown( KeyEvent event );
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    frown::ParticleSystem* mSystem;
    bool            showNextFrame;
    bool            doShow;
    bool            mPausedAnimation;
};
void FrownParticleSystemApp::prepareSettings(AppBasic::Settings* settings)
{
}
void FrownParticleSystemApp::setup()
{
    mSystem = new frown::ParticleSystem(262144);
}

void FrownParticleSystemApp::mouseDown( MouseEvent event )
{
    
}

void FrownParticleSystemApp::keyDown( KeyEvent event )
{
}

void FrownParticleSystemApp::update()
{
    mSystem->update();
}

void FrownParticleSystemApp::draw()
{
    gl::clear( Color( 0, 0, 0 ) );
    mSystem->draw();
}

CINDER_APP_NATIVE( FrownParticleSystemApp, RendererGl )
