//
//  FIFLogger.h
//  FIFTagHandler
//
//  Created by Med on 05/06/14.
//  Copyright (c) 2014 fifty-five. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "TAGLogger.h"

/**
 *  A class that provides a logger for the FIFTagHandler framework
 */
@interface FIFLogger : NSObject {
    TAGLoggerLogLevelType level;
    NSString *format;
    NSString *context;
}


/** The log format */
@property (nonatomic, retain) NSString *format;


/** The logging level */
@property (assign, readonly) TAGLoggerLogLevelType level;


/** The framework name */
@property (nonatomic, retain) NSString *context;


/**
 *  Initialize the logger with a context
 *
 *  @param aContext The Context
 *
 *  @return The created logger
 */
- (id)initLogger:(NSString *)aContext;

/**
 *  Set the logging level
 *
 *  @param logLevel the logging level
 */
- (void)setLevel:(TAGLoggerLogLevelType)logLevel;


/**
 *  Set the logging format
 *
 *  @param logFormat the logging format
 */
- (void)setFormat:(NSString *)logFormat;


/**
 *  This method logs a warning about an
 *  uncastable param.
 *
 *  @param paramName The uncastable param name
 *  @param type      The type
 */
- (void)logUncastableParam:(NSString *)paramName
                    toType:(NSString *)type;


/**
 *  This method logs a warning about
 *  a missing initialization of the framework
 */
- (void)logUninitializedFramework;



/**
 *  This method logs a setter success
 *
 *  @param paramName The set param
 *  @param value     The set value
 */
- (void)logParamSetWithSuccess:(NSString *)paramName
                     withValue:(id)value;


/**
 *  This method logs a warning about an
 *  unknown param.
 *
 *  @param paramName The unknown param
 */
- (void)logUnknownParam:(NSString *)paramName;


/**
 *  This method logs a warning about a
 *  missing value from a predifined value set
 *
 *  @param value          The value
 *  @param possibleValues The value set
 */
- (void)logNotFoundValue:(NSString *)value
                  forKey:(NSString *)key
              inValueSet:(NSArray*)possibleValues;


/**
 *  This method logs a warning about
 *  a missing required parameter.
 *
 *  @param paramName  The missing param name
 *  @param methodName The method name
 */
- (void)logMissingParam:(NSString *)paramName
               inMethod:(NSString *)methodName;

/**
 *  Log the message with the stradard format.
 *
 *  @param intentLevel   The level in which the message should be recorded.
 *  @param messageFormat The message format.
 *  @param ...           The values of the printed format.
 */
void FIFLog(TAGLoggerLogLevelType intentLevel, NSString *messageFormat, ...) NS_FORMAT_FUNCTION(2,3);
@end
