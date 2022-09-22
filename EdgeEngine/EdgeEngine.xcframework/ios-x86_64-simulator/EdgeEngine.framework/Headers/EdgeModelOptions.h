//
//  EdgeModelOptions.h
//  EdgeStoreiOSProject
//
//  Created by Edge Developer on 22/09/2022.
//

#ifndef EdgeModelOptions_h
#define EdgeModelOptions_h
//@interface EdgeModelOptions:NSObject {
//- (id) initWithTFLOptions: (struct TFLOptions *) tflOptions;
//@end
struct EdgeModelOptions{
    struct TFLOptions *tfliteOptions;
    
};
struct TFLOptions{
    
    /// The maximum number of CPU threads that the interpreter should run on. The default is `-1`
    /// indicating that the `Interpreter` will decide the number of threads to use.
    int threadCount;
    
    
    /// Indicates whether an optimized set of floating point CPU kernels, provided by XNNPACK, is
    /// enabled.
    ///
    /// - Experiment:
    /// Enabling this flag will enable use of a new, highly optimized set of CPU kernels provided
    /// via the XNNPACK delegate. Currently, this is restricted to a subset of floating point
    /// operations. Eventually, we plan to enable this by default, as it can provide significant
    /// performance benefits for many classes of floating point models. See
    /// https://github.com/tensorflow/tensorflow/blob/master/tensorflow/lite/delegates/xnnpack/README.md
    /// for more details.
    ///
    /// - Important:
    /// Things to keep in mind when enabling this flag:
    ///
    ///     * Startup time and resize time may increase.
    ///     * Baseline memory consumption may increase.
    ///     * Compatibility with other delegates (e.g., GPU) has not been fully validated.
    ///     * Quantized models will not see any benefit.
    ///
    /// - Warning: This is an experimental interface that is subject to change.
    bool isXNNPackEnabled;
    
    
    /// Try to use the Core ML Neural Engine - Provides hardware acceleration (faster execution). If model throws error during inference try turning both
    ///``isCoreMLAccelearationEnabled`` and ``isMetalAccelerationEnabled`` to off.
    ///
    /// If device does not contain the engine then Interpreter will try to use the Metal Delegate if ``isMetalAccelerationEnabled`` is true.
    bool isCoreMLAccelearationEnabled;
    
    /// Try to use Metal Delegate if Core ML delegate is not supported - Provides hardware acceleration (faster execution)
    bool isMetalAccelerationEnabled;
};



#endif /* EdgeModelOptions_h */
