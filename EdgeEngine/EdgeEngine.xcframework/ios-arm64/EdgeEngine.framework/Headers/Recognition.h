//
//  Recognition.h
//  EdgeStoreObjC-sample
//
//  Created by Edge Developer on 03/08/2022.
//

#include <Foundation/Foundation.h>
#import "CoreGraphics/CoreGraphics.h"
#import "Label.h"
#import "KeyPoints.h"

/*! @brief GenericOpaque is  an Opaque structure which contain object of GenericDetection Class of C++ .*/
struct GenericOpaque;

/// Recognition Class is use to initilize internal object of GenericOpaque. genericOpaque is a object of GenericOpaque to initialize GenericDetection Class of C++.This Class contain data of GenericDetection Class for further Processing.
@interface Recognition:NSObject{
@public struct GenericOpaque* genericOpaque;
}

/// This contain the float value. confidence discribes that how much Edge Model is confident about recognising the object. if confidence >0.5 than the detected object is true.
@property (nonatomic) float confidence;
/// This contain the Label class.
@property  (nonatomic) Label *label;
/// This contain the points that describe the size of object detected by Edge Model.
@property (nonatomic) CGRect location;
/// This contain the Keypoints class.
@property  (nonatomic) KeyPoints *keypoints;


/// Initialize GenericDetection Class object from GenericOpaque to internal object to use in further methods.
/// @param detectionBuffer It is an GenericOpaque object which contain GenericDetection Class from external Class object or Method.
- (id) initWithGenericDetection: (struct GenericOpaque *) detectionBuffer;
- (void) dealloc;

@end




