//
//  Segmentation.h
//  EdgeStoreObjC-sample
//
//  Created by Edge Developer on 16/08/2022.
//




#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>


/*! @brief OpaqueSegmentation is  an Opaque structure which contain object of SemanticSegmentationHolder Class of C++ .*/
struct OpaqueSegmentation;

/// Segmentation Class is use to initilize internal object of OpaqueSegmentation. opaqueSegmentation is a object of OpaqueSegmentation to initialize SemanticSegmentationHolder Class of C++. This Class contain data of SemanticSegmentationHolder Class for further Processing.
@interface Segmentation:NSObject{
 struct OpaqueSegmentation* opaqueSegmentation;
}

/// This contain the Opencv Mat and Convert it to CVPixelBufferRef and return CVPixelBufferRef.
@property (nonatomic) CVPixelBufferRef rawMask;

/// Initialize SemanticSegmentationHolder Class object from OpaqueSegmentation to internal object to use in further methods.
/// @param bufferResultsHolder It is an OpaqueSegmentation object which contain SemanticSegmentationHolder Class object from external Class or Method.
- (id) initWithSemanticSegmentation: (struct OpaqueSegmentation *) bufferResultsHolder;
/// Pass custom Heigt, Width and Aspect Reatio of Image and this method return the result as CVPixelBufferRef object.
/// @param width Width of Image.
/// @param height Height of imag.
/// @param aspectRatio aspectRatio value 'Yes' or 'No'.
- (CVPixelBufferRef) getMask:(int) width height:(int) height aspectRatio:(bool) aspectRatio;
- (void) dealloc;

@end

