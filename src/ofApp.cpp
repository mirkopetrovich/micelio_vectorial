#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    gui.setup();
    gui.add(prob1.set("probabilidad",0.001, 0, 0.02));
    gui.add(bump.set("bump",0.2,0, 1.));
    gui.add(tam.set("tamano",1,1, 10));
    gui.add(rescaleRes.set("rescale",6,1,50));
    gui.add(vectorial.set("vectorial",1));
    gui.add(multiplica.set("multiplica",0));
    gui.add(prob2.set("probabilidad",0.01,0, 0.02));
    
    ofSetCircleResolution(50);
    
	capture = false;
    pausa = true;
    hifa temporal;
    temporal.setup();
    micelio.push_back(temporal);
    micelio.push_back(temporal);
    micelio.push_back(temporal);
    micelio.push_back(temporal);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
	if(capture){
		output.beginEPS("micelio_" + ofToString(micelio.size()) + "_" + ofGetTimestampString("%H-%M-%S") + ".ps");
	}
    
   
    for (int i=0;i<micelio.size();i++) {                    // loop por todas las hifas
        micelio[i].bum = bump;
        micelio[i].puntos.push_back(glm::vec3());           //agregamos un punto a la hifa
        int last = micelio[i].puntos.size()-1;              //last = último punto
        micelio[i].puntos[last].x=micelio[i].posicion.x;    //asigna cabeza de micelio[0] último punto x
        micelio[i].puntos[last].y=micelio[i].posicion.y;    //               ''                        y
        int numPts = micelio[i].puntos.size();              //numPts = cantidad de puntos micelio[0]

       if (vectorial)   {
        
        output.setColor(0xFFFFFF);
        output.noFill();
        output.setLineWidth(tam);
        output.beginShape();
           
           for(int j = 0; j < numPts; j++){
               if(j == 0 || j == numPts -1){
                   output.curveVertex(micelio[i].puntos[j].x,micelio[i].puntos[j].y);
               }
               if(j % rescaleRes == 0) {
                   output.curveVertex(micelio[i].puntos[j].x, micelio[i].puntos[j].y);
                   }
               }
           output.endShape();
           }

       else {
        ofSetHexColor(0xFFFFFF);
        ofNoFill();
        ofSetLineWidth(tam);
        ofBeginShape();
       
        
        for(int j = 0; j < numPts; j++){
            if(j == 0 || j == numPts -1){
                    ofCurveVertex(micelio[i].puntos[j].x,micelio[i].puntos[j].y);
                }
            if(j % rescaleRes == 0) {
                ofCurveVertex(micelio[i].puntos[j].x, micelio[i].puntos[j].y);
                }
            }
        ofEndShape();
        }
        
        
        if (!pausa) {
        
            
      //  if micelio[i].posicion
            
            if (micelio[i].posicion.distance(ofVec2f(mouseX,mouseY))<scroll&&multiplica) {
                probabilidad=prob2;
            }
            else {
                probabilidad=prob1;
            }
            
            
        if (ofRandom(0,1)<probabilidad) micelio.push_back(micelio[i]);
            
            micelio[i].update();
        
     
            
            
            
        
        }
    }
    
    
	if(capture){
		output.endEPS();
		capture =false;
	}
    gui.draw();
    ofSetHexColor(0x00FFFF);
    ofDrawCircle(mouseX, mouseY, scroll);
    //ofDrawBitmapString(scroll,mouseX,mouseY);
    
    }

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
   
    
    if(key == 'd'){
        int total= micelio.size();
               for (int i=0;i<total;i++) {
                   micelio.push_back(micelio[i]);
               }
    }
    
    
	if(key == ' '){
		capture = true;
	}
    
    if(key == 'c') {
           micelio.clear();
           hifa temporal2;
           temporal2.setup();
           temporal2.posicion.x=mouseX;
           temporal2.posicion.y=mouseY;
           
             micelio.push_back(temporal2);
    }
    
    if(key == '1') {
      
        hifa temporal2;
           temporal2.setup();
           temporal2.posicion.x=mouseX;
           temporal2.posicion.y=mouseY;
           
             micelio.push_back(temporal2);
    }
    
    
    if(key == '2') {
         
          hifa temporal2;
             temporal2.setup();
             temporal2.posicion.x=mouseX;
             temporal2.posicion.y=mouseY;
             
               micelio.push_back(temporal2);
               micelio.push_back(temporal2);
      }
    
    
    if(key == '3') {
        
          hifa temporal2;
             temporal2.setup();
             temporal2.posicion.x=mouseX;
             temporal2.posicion.y=mouseY;
             
               micelio.push_back(temporal2);
               micelio.push_back(temporal2);
               micelio.push_back(temporal2);
      }
    
    
    
    
    if(key == '4') {
       
        hifa temporal2;
           temporal2.setup();
           temporal2.posicion.x=mouseX;
           temporal2.posicion.y=mouseY;
           
        micelio.push_back(temporal2);
        micelio.push_back(temporal2);
        micelio.push_back(temporal2);
        micelio.push_back(temporal2);
        
    }
    
    if(key == 'p') {
        pausa = !pausa;
      }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

   
   
    
    
    //we add a new point to our line
    
    
  
 //   micelio.push_back(micelio[0]);
  //  pts.push_back(glm::vec3());
   // int last = pts.size()-1;

    //pts[last].x = ofRandom(640);
    //pts[last].y = ofRandom(480);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    
        hifa temporal2;
           temporal2.setup();
           temporal2.posicion.x=mouseX;
           temporal2.posicion.y=mouseY;
           
        micelio.push_back(temporal2);
        micelio.push_back(temporal2);
        micelio.push_back(temporal2);
        micelio.push_back(temporal2);
        
    }
    
    // micelio.clear();
    
 
  /*  int total= micelio.size();
     for (int i=0;i<total;i++) {
         micelio.push_back(micelio[i]);
     } */
    
   
       
    

    //lets store the first point of the line
    //pts.push_back(glm::vec3());
    //pts[0].x = x;
    //pts[0].y = y;




//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY ) {

    scroll += scrollY;
    if (scroll<0) scroll=0;
    
}
