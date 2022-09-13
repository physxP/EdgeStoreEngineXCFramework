//
//  Label.h
//  EdgeStoreObjC-sample
//
//  Created by Edge Developer on 05/08/2022.
//


#include <Foundation/Foundation.h>

/*! @brief OpaqueLabel is  an Opaque structure which contain object of Detection Class of C++ .*/
struct  OpaqueLabel;

/// Label Class is use to get the name and classId of main object which is recognised by Edge Model. name represent the object like "Person" and classId represent it with unique id.This Class contain data of Detection Class for further Processing.
@interface Label:NSObject{
@public struct  OpaqueLabel* opaqueLabel;
@public  NSString* name;
@public int classId;
}

/// Initialize Detection Class object from OpaqueLabel to internal object to use in further methods.
/// @param protoBuffer  It is an OpaqueLabel object which contain Detection Class from external Class object or Method.
- (id) initWithDetection: (struct OpaqueLabel *) protoBuffer;
- (void) dealloc;
@end

