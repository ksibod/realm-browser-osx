// Generated by Apple Swift version 2.1.1 (swiftlang-700.1.101.15 clang-700.1.81)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__has_include) && __has_include(<uchar.h>)
# include <uchar.h>
#elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
#endif

typedef struct _NSZone NSZone;

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted) 
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
#endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"


/// An abstract class manages the common logic for setting up objects that can export the contents of Realm files to another format.
SWIFT_CLASS("_TtC14RealmConverter12DataExporter")
@interface DataExporter : NSObject
@property (nonatomic, copy) NSString * __nonnull realmFilePath;

/// Create a new instance of the exporter object
///
/// \param realmFilePath An absolute path to the Realm file to be exported
- (nonnull instancetype)initWithRealmFileAtPath:(NSString * __nonnull)realmFilePath OBJC_DESIGNATED_INITIALIZER;

/// Exports all of the contents of the provided Realm file to the designated output folder.\Warning 
///
/// This method must be overridden by a subclass, that does <em>not</em> call <code>super
/// </code>
- (BOOL)exportToFolderAtPath:(NSString * __nonnull)outputFolderPath withError:(NSError * __nullable * __null_unspecified)error;
@end



/// Provided a Realm file and an output destination folder, CSVDataExporter can export the contents of a Realm file to a series of CSV files.
///
/// A single CSV file is created for each table in the Realm file,
/// with strings being escaped in the default CSV standard.
SWIFT_CLASS_NAMED("CSVDataExporter")
@interface RLMCSVDataExporter : DataExporter

/// The delimiter symbol used to separate each property on each row. Defaults to the CSV standard ',' comma.
@property (nonatomic, copy) NSString * __nonnull delimiter;

/// When it's necessary to escape a Realm property on a CSV row, this is the escape symbol Defaults to the CSV standard '"' double-quotes.
@property (nonatomic, copy) NSString * __nonnull escapeQuotes;

/// Takes the provided Realm file and exports each table to a CSV file in the provided output folder.
///
/// \param outputFolderpath An absolute path to a folder where the transformed files will be saved
- (BOOL)exportToFolderAtPath:(NSString * __nonnull)outputFolderPath withError:(NSError * __nullable * __null_unspecified)error;
- (nonnull instancetype)initWithRealmFileAtPath:(NSString * __nonnull)realmFilePath OBJC_DESIGNATED_INITIALIZER;
@end

enum Encoding : NSUInteger;
@class RLMImportSchema;
@class RLMRealm;


/// An abstract class manages the common logic for setting up objects that can take a group of files, and convert them into a new Realm file.
SWIFT_CLASS_NAMED("DataImporter")
@interface RLMDataImporter : NSObject
@property (nonatomic, readonly, copy) NSArray<NSString *> * __nonnull files;
@property (nonatomic, readonly) enum Encoding encoding;

/// Creates a new instance of DataImporter, taking a single file that will be converted into a Realm file.
///
/// <ul><li>paramter encoding: The text encoding of the file being imported</li></ul>
/// \param file An absolute path to the file that will be imported
- (nonnull instancetype)initWithFile:(NSString * __nonnull)file encoding:(enum Encoding)encoding;

/// Creates a new instance of DataImporter, taking an array of files that will be converted into a Realm file.
///
/// <ul><li>paramter encoding: The text encoding of the file being imported</li></ul>
/// \param files An array of absolute paths to the files to import
- (nonnull instancetype)initWithFiles:(NSArray<NSString *> * __nonnull)files encoding:(enum Encoding)encoding OBJC_DESIGNATED_INITIALIZER;

/// Creates a new, empty Realm file, formatted with the schema properties provided with the provided ImportSchema object.
///
/// \param output An absolute path to the folder that will hold the new Realm file
///
/// \param schema The import schema with which this file will be created
- (RLMRealm * __nullable)createNewRealmFileAtPath:(NSString * __nonnull)output withSchema:(RLMImportSchema * __nonnull)schema error:(NSError * __nullable * __null_unspecified)error;
@end



/// Provided a Realm file and an output destination folder, CSVDataExporter can export the contents of a Realm file to a series of CSV files.
///
/// A single CSV file is created for each table in the Realm file,
/// with strings being escaped in the default CSV standard.\Warning 
///
/// Presently, relationships between Realm objects are
/// not captured in the CSV files.
SWIFT_CLASS_NAMED("CSVDataImporter")
@interface RLMCSVDataImporter : RLMDataImporter
- (RLMRealm * __nullable)importToPath:(NSString * __nonnull)path withSchema:(RLMImportSchema * __nonnull)schema error:(NSError * __nullable * __null_unspecified)error;
- (nonnull instancetype)initWithFiles:(NSArray<NSString *> * __nonnull)files encoding:(enum Encoding)encoding OBJC_DESIGNATED_INITIALIZER;
@end



typedef SWIFT_ENUM(NSUInteger, Encoding) {
  EncodingUTF8 = 0,
};


SWIFT_CLASS_NAMED("ImportObjectSchema")
@interface RLMImportObjectSchema : NSObject
@property (nonatomic, copy) NSString * __nonnull objectClassName;
@end


@interface RLMImportObjectSchema (SWIFT_EXTENSION(RealmConverter))
@property (nonatomic, readonly, copy) NSString * __nonnull description;
@property (nonatomic, readonly, copy) NSString * __nonnull debugDescription;
@end


SWIFT_CLASS_NAMED("ImportSchema")
@interface RLMImportSchema : NSObject
@end


@interface RLMImportSchema (SWIFT_EXTENSION(RealmConverter))
@property (nonatomic, readonly, copy) NSString * __nonnull description;
@property (nonatomic, readonly, copy) NSString * __nonnull debugDescription;
@end

typedef SWIFT_ENUM(NSInteger, ImportSchemaFormat) {
  ImportSchemaFormatCSV = 0,
  ImportSchemaFormatXLSX = 1,
};



/// ImportSchemaGenerator will analyze the contents of files provided to it, and intelligently generate a schema definition object with which the structure of a Realm file can be created.
///
/// This is then used to map the raw data to the appropriate properties
/// when performing the import to Realm.
SWIFT_CLASS_NAMED("ImportSchemaGenerator")
@interface RLMImportSchemaGenerator : NSObject

/// Creates a new instance of ImportSchemaGenerator, specifying a single file with which to import
///
/// \param file The absolute file path to the file that will be used to create the schema.
///
/// \param encoding The text encoding used by the file.
- (nonnull instancetype)initWithFile:(NSString * __nonnull)file encoding:(enum Encoding)encoding;

/// Creates a new instance of ImportSchemaGenerator, specifying a list of files to analyze.
///
/// \param files An array of absolute file paths to each file that will be used for the schema.
///
/// \param encoding The text encoding used by the file.
- (nonnull instancetype)initWithFiles:(NSArray<NSString *> * __nonnull)files encoding:(enum Encoding)encoding OBJC_DESIGNATED_INITIALIZER;

/// Processes the contents of each file provided and returns a single ImportSchema object representing all of those files.
- (RLMImportSchema * __nullable)generatedSchemaWithError:(NSError * __nullable * __null_unspecified)error;
@end


SWIFT_CLASS_NAMED("XLSXDataImporter")
@interface RLMXLSXDataImporter : RLMDataImporter
- (RLMRealm * __nullable)importToPath:(NSString * __nonnull)path withSchema:(RLMImportSchema * __nonnull)schema error:(NSError * __nullable * __null_unspecified)error;
- (nonnull instancetype)initWithFiles:(NSArray<NSString *> * __nonnull)files encoding:(enum Encoding)encoding OBJC_DESIGNATED_INITIALIZER;
@end

#pragma clang diagnostic pop