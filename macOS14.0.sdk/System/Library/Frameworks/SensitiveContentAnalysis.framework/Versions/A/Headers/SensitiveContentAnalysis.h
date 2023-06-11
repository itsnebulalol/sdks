//
//  SensitiveContentAnalysis.h
//  SensitiveContentAnalysis
//
//  Created by Andrey Cherkashin on 4/11/23.
//

#import <Foundation/Foundation.h>

// In this header, you should import all the public headers of your framework using statements like #import <SensitiveContentAnalysis/PublicHeader.h>

#if (!TARGET_OS_TV && !TARGET_OS_XR)
#import <SensitiveContentAnalysis/SCSensitivityAnalyzer.h>
#endif // !TARGET_OS_TV
