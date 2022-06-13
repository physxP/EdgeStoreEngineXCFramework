# Media Pipe Face Detection
## Overview

MediaPipe Face Detection is an ultrafast face detection solution that comes with 6 landmarks and multi-face support. It is based on [BlazeFace](https://arxiv.org/abs/1907.05047), a lightweight and well-performing face detector tailored for mobile GPU inference. The detector’s super-realtime performance enables it to be applied to any live viewfinder experience that requires an accurate facial region of interest as an input for other task-specific models, such as 3D facial keypoint estimation (e.g., [MediaPipe Face Mesh](https://google.github.io/mediapipe/solutions/face_mesh.html)), facial features or expression classification, and face region segmentation. BlazeFace uses a lightweight feature extraction network inspired by, but distinct from [MobileNetV1/V2](https://ai.googleblog.com/2018/04/mobilenetv2-next-generation-of-on.html), a GPU-friendly anchor scheme modified from [Single Shot MultiBox Detector (SSD)](https://arxiv.org/abs/1512.02325), and an improved tie resolution strategy alternative to non-maximum suppression. For more information about BlazeFace, please see the [Resources](https://google.github.io/mediapipe/solutions/face_detection.html#resources) section.
![Demo](https://google.github.io/mediapipe/images/mobile/face_detection_android_gpu.gif)

## iOS Quick Start

This model is available in **v0.2.1** or above for the sdk. To install latest sdk version add following line in your Podfile :
```ruby
pod 'EdgeStoreEngine' , git: 'https://github.com/physxP/EdgeStoreEngineXCFramework.git'
```


### Running the Model
Download the models from google drive: https://drive.google.com/drive/folders/1-wp-B-MdiW86mvvR53nDptUNal6WMjji?usp=sharing

Place the model.edgem file in your xcode project and run the following code:


```swift

let modelPath:String = Bundle.main.path(forResource: "model", ofType: "edgem")!
let model =  try EdgeModel(modelPath: modelPath)

let image = //your input image

let results: Recognitions = try model.run(inputs:[image])
```
We support following input formats for images:
- CvPixelBuffer  (Recommended)
- UIImage (Slow)

And thats it! You have successfully run a complex AI model just in a few lines. Now it is time to
visualize the results.


### Visualizing the Results

To quickly visualize the results:

```swift
let resultsImage : CGImage = results.draw(image:pixelBuffer)
```

Drawing functionality is available for:
- UIImage
- CVPixelBuffer
- CGImage

resultsImage has results directly drawn on it.




### Interpreting and Using Results

The output *results* variable has type Recognitions that is a type of List. All the useful
information the model provides is compacted into this variable. Not matter your use case the output of model will always be

For example if our model detects two persons in an image then results List will contain two
elements. Each element is of type Recognition and represents detection of each face


```swift
for face in results {
    // how sure we are that this is actually a person. Value between 0 and 1, represents probability of detection
    let confidence: CGFloat = face.confidence!
    // the pixel location of person's bounding box in the image
    let location: CGRect = face.location!
    // Keypoints detected on the person
 
}
```
### Coordinate System
Our coordinate system is same as used in UIKit. i.e.  our origin is at top left corner of image, with x axis to the right and y axis to the bottom.
![Coordinates Demo](https://files.seeedstudio.com/wiki/Wio-Terminal/img/grids.jpg)

The recognitions object returned after model execution provides coordinates in image domain. i.e. 0 < x < Input Image Width and 0 < y < Input Image Height. 

You can directly apply transformations on Recognitions object by using the Recognitions.applying function with CGAffineTransform.