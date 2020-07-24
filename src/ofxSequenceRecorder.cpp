//
//  ofxSequenceRecorder.cpp
//  sequenceRecorder
//
//  Created by okuyama on 2020/03/23.
//


#include "ofxSequenceRecorder.h"

void ofxSequenceRecorder::setup(){
    dirPath = ofToString(ofGetTimestampString());
    frame = 0;
    
    pixelBufferBack.allocate(ofGetWidth()*ofGetHeight()*4,GL_DYNAMIC_READ);
    pixelBufferFront.allocate(ofGetWidth()*ofGetHeight()*4,GL_DYNAMIC_READ);
}
void ofxSequenceRecorder::setup(glm::vec2 resolution){
    
    dirPath = ofToString(ofGetTimestampString());
    frame = 0;
    
    pixelBufferBack.allocate(resolution.x*resolution.y*4,GL_DYNAMIC_READ);
    pixelBufferFront.allocate(resolution.x*resolution.y*4,GL_DYNAMIC_READ);
    
}

//
//void ofxSequenceRecorder::VezerSetup(string path){
//    vector<ofxVezer::Composition> comps = ofxVezer::ParserCereal::load("0130.xml", "testt.bin");
//    comp = comps[0];
//    comp.combine(comps[1]);
//    parser.redraw(comp);
//}
//
//void ofxSequenceRecorder::VezerUpdate(){
//    //  int frame = int(ofGetElapsedTimef() * comp.fps)  % comp.length;
//    //  frame = ofGetFrameNum()+offsetFrame;
//    provider.setCurrentTracks(comp, frame);
//    while ( provider.hasWaitingMessages() ) {
//        ofxOscMessage m;
//        provider.getNextMessage(&m);
//        string addr = m.getAddress();
//        if(addr == "/hoge"){
//        }
//    }
//}

void ofxSequenceRecorder::draw(){
    
    ofDrawBitmapString("frame"+ofToString(ofGetFrameNum()),0.0,10.0);
}


void ofxSequenceRecorder::record(ofFbo& scene){
    if(isRecording){
        scene.getTexture().readToPixels(pixels);
        pixelBufferFront.bind(GL_PIXEL_UNPACK_BUFFER);
        unsigned char * p = pixelBufferFront.map<unsigned char>(GL_READ_ONLY);
        pixels.setFromExternalPixels(p,scene.getWidth(),scene.getHeight(),OF_PIXELS_RGBA);
        
        ofSaveImage(pixels,dirPath+"/"+ofToString(ofGetFrameNum())+".png");
        pixelBufferFront.unmap();
        swap(pixelBufferBack,pixelBufferFront);
    }
}


