#pragma once

#include "ofxVectorGraphics.h"
#include "ofMain.h"
#include "hifa.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void mouseScrolled(int x, int y, float scrollX, float scrollY );

		ofxVectorGraphics output;
		bool capture;
    bool pausa;

        vector <hifa> micelio;
    ofxPanel gui;
    ofParameter<float> prob1,prob2,tam,bump;
    ofParameter<int> rescaleRes;
    ofParameter<bool> vectorial,multiplica;
    
    float scroll, probabilidad;


};


