//
//  ofxSequenceRecorder.hpp
//  sequenceRecorder
//
//  Created by okuyama on 2020/03/23.
//

#pragma once
#include "ofMain.h"
#include "ofxVezer.h"
#include "ParserCereal.h"

class ofxSequenceRecorder{
public:
    
    //----Vezer
    ofxVezer::Parser parser;
    ofxVezer::Composition comp;
    ofxVezer::Provider provider;
    void setup();
    void setup(string vezerPath,int desireFrame);
    void VezerSetup(string path);
    void VezerUpdate();
    
    void record(ofFbo& scene);
    
    
    ofBufferObject pixelBufferBack, pixelBufferFront;
    
    ofPixels pixels;
    int frame= 0;
    bool isRecording = true;
    string dirPath;

};
