#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>
#import "Results.h"
#import "EdgeModelOptions.h"



/// EdgeModel is a Class which recognise the object from given image and draw the points on image to show the object and sub parts of an obect.
@interface EdgeModel : NSObject


/// This object contain the Path of Model in the form of NSString.
@property NSString *modelPath;
/// This object contain the Path of Graph in the form of NSString.
@property NSString *graphPath;

/// Initialize  it with the Path of Edgem Model to perform further operation.
/// @param edgemPath Path of Edgem Model.
- (id) initWithEdgemPath: (NSString*) edgemPath;
- (id) initWithEdgemPathAndEdgeModelOptions: (NSString*) edgemPath EdgeModelOptions: (struct EdgeModelOptions *) edgeModelOptions;
//- (void) run: (NSString*) inputPath : (NSString*) outputPath;
/// Run method is use to recognize object from given image and give Results in return.
/// @param inputBuffer CVPixelBufferRef.
- (Results *)run:(CVPixelBufferRef)inputBuffer;


@end

