//
//  Results.h
//  EdgeStoreObjC-sample
//
//  Created by Edge Developer on 05/08/2022.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Segmentation.h"


/*! @brief ResultOpaque is  an Opaque structure which contain object of ProtoResultHolder Class of C++ .*/
struct ResultOpaque;

/// Result Class is use to initilize internal object of ResultOpaque. resultOpaque is a object of ResultOpaque to initialize ProtoResultHolder Class of C++. This Class contain data of ProtoResultHolder Class for further Processing.
@interface Results : NSObject{
 struct ResultOpaque* resultOpaque;
    
}

/// This contain the list of Recognition Class.That list contains the data of recognitions detected by Edge Model.
@property (nonatomic) NSMutableArray *recognitions;
/// This contain the Segmentation Class.
@property (nonatomic) Segmentation *smanticSegmentationMask;


/// Initialize ProtoResultHolder Class object from ResultOpaque to internal object to use in further methods.
/// @param detection It is an ResultOpaque object which contain ProtoResultHolder Class object from external Class or Method.
- (id) initWithResultHolder:(struct ResultOpaque *) detection;
/// This method draw the recognised result to an image.
/// @param pixelBuffer The formate of an image should be a CVPixelBufferRef.
- (void) drawResults: (CVPixelBufferRef) pixelBuffer;
/// This method transform the coordinates from given matrix (Form of:CGAffineTransform) and return Result Class object to use it for further transformation.
/// @param affineTransformation The Matrix is in the form of CGAffineTransform.
- (Results *) affineCoordinatesTransform2d:(CGAffineTransform) affineTransformation;
- (void) dealloc;

@end


