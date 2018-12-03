#include "testui.h"

#include "testscene.h"
#include "ofxscenemanager.h"

TestUI::TestUI()
{
    canvas.addLabelButton("BUTTON", false);

    ofAddListener(canvas.newGUIEvent, this, &TestUI::uiEvent);
}

void TestUI::uiEvent(ofxUIEventArgs &event)
{
    if (event.widget->getState() == OFX_UI_STATE_OVER) {
        ofxSetNextScene(new TestScene());
    }
}


