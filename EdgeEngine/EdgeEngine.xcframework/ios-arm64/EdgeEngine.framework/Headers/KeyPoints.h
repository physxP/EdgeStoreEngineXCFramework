//
//  KeyPoints.h
//  EdgeStoreObjC-sample
//
//  Created by Edge Developer on 11/08/2022.
//

#import <Foundation/Foundation.h>

/*! @brief OpaquePoints is  an Opaque structure which contain object of Points class of C++ .*/
struct  OpaquePoints;

/// KeyPoints Class is use to initialize Keypoint Class and get Skeleton Method. opaquePoints is a object of OpaquePoints to initialize Points Class of C++.This Class contain data of Points Class for further Processing.
@interface KeyPoints:NSObject{
@public struct  OpaquePoints* opaquePoints;
}
/// Keypoint Return the list of keyPoint Class.
@property (nonatomic) NSMutableArray *Keypoint;

/// skeleton Return the list of Parent and Child IDs that use to make a relational graph of points.
@property (nonatomic) NSMutableArray *skeleton;
/// Initialize Point Class object from OpaquePoints to internal object to use in further methods.
/// @param pointsBuffer It is an OpaquePoints object which contain Points Class object from external Class or Method.
- (id) initWithPoints: (struct OpaquePoints *) pointsBuffer;
- (void) dealloc;
@end

