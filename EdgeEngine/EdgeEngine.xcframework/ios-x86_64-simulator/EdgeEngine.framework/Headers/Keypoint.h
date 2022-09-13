//
//  Keypoint.h
//  EdgeStoreObjC-sample
//
//  Created by Edge Developer on 11/08/2022.
//
#include <Foundation/Foundation.h>

/*! @brief OpaquePoint is  an Opaque structure which contain object of Point Class of C++ .*/
struct  OpaquePoint;

/// KeyPoint Class  is use to get (x, y) points and name of class and confidence. opaquePoint is a object of OpaquePoint to initialize Point Class of C++.This Class contain data of Point Class for further Processing.
@interface Keypoint:NSObject{
@public struct  OpaquePoint* opaquePoint;
}
/// Point x contain float value.
@property (nonatomic) float x;
/// Point y contain float value.
@property (nonatomic) float y;
/// This contaion the name of class which represent the sub part of a detected object by Edge Model.
@property (nonatomic) NSString *name;
/// This contain the float value. confidence discribes that how much Edge Model is confident about recognising the sub-object. if confidence >0.5 than the detected object is true.
@property (nonatomic) float confidence;

/// Initialize Point Class object from OpaquePoint to internal object to use in further methods.
/// @param pointBuffer It is an OpaquePoint object which contain Point Class object from external Class or Method.
- (id) initWithPoint: (struct OpaquePoint *) pointBuffer;
- (void) dealloc;
@end

