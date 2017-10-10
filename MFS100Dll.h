#ifndef MFSDLLH
#define MFSDLLH

int MFS100Init(unsigned char* serialno);
int MFS100InitWithKey(unsigned char* serialno,unsigned char* UnlockKey);
int MFS100Uninit();
int MFS100StartXcan();
int MFS100StopXcan();
int MFS100GetFrame(unsigned char* FinalFrame500DPI);
int MFS100GetWidth();
int MFS100GetHeight();
int MFS100DeviceConnected();
int MFS100RotateImage(int Direction);
int MFS100ExtractISO(unsigned char* RawImage, unsigned char* Iso_19794_2_Template, int *TemplateLength);
int MFS100GetQuality(unsigned char* RawImage, int *Quality, int *Contrast, int *NFIQ);
int MFS100ExtractANSITemplate(unsigned char* RawImage, unsigned char *Ansi_19794_2_Template, int *TemplateLength);
int MFS100ExtractISOImage(unsigned char* RawImage,unsigned char *ISOImage, int *ISOImageSize, unsigned char FingerPosition);


int MFS100ExtractWSQImage(unsigned char* FinalFrame, unsigned char **WSQImage, int *WSQImageSize, float compressionRatio);

int MFS100MatchISO(unsigned char* probeTemplate,unsigned char* galleryTemplate, int maxRotation, int* score);
int MFS100MatchANSI(unsigned char* probeTemplate,unsigned char* galleryTemplate, int maxRotation, int* score);
int MFS100ConvertRawToBmp(unsigned char* frame, unsigned char* Imagedata, int ht, int wd);
typedef void(_stdcall * MFS100AutoCaptureCallback)(unsigned char*);
int MFS100AutoCapture(MFS100AutoCaptureCallback mfs100AutoCaptureCallback, int Timeout, int MinimumQuality, unsigned char *AutoCaptureRawImage, unsigned char* BitmapImageData, unsigned char* Iso_19794_2_Template, int * ISO_TemplateLength, unsigned char* Ansi_378_2004_Template, int * ANSI_TemplateLength, int *Quality, int *NFIQ);


int MFS100GetSDKVersion(); //earlier defination MFS100GetVersion
int MFS100GetInfo(char* Make, char* Model);
int MFS100IsLive(unsigned char* FinalFrame500DPI, int threshold, int *score);
int MFS100ReadSerial(unsigned char* serialno);

#define MFS100_E_SUCCESS					0               //Success
#define MFS100_E_INVALIDPARAM				-1101           //Invalid Parameters
#define MFS100_E_BLANKIMAGE                 -1114           //Image is blank or contains non-recognizable fingerprint
#define MFS100_E_NOT_GOOD_IMAGE             -1115           //Input image is not good
#define MFS100_E_EXTRACTOR_INIT_FAILED      -1116           //Extractor Library cannot Initialize
#define MFS100_E_FILE_IO                    -1117           //Error occured while opening/reading file
#define MFS100_E_MEMORY                     -1120           //Memory allocation failed
#define MFS100_E_NULLPARAM                  -1121           //Null Parameters
#define MFS100_E_OTHER                      -1122           //Other Error
#define MFS100_E_BAD_LICENSE                -1129           //Provided license is not valid, or no license was found
#define MFS100_E_BAD_FORMAT                 -1132           //Unsupported Format
#define MFS100_E_BAD_VALUE                  -1133           //Invalid Value Provided
#define MFS100_E_NOT_IMPLEMENTED            -1134           //Function not implemented
#define MFS100_E_BAD_TEMPLATE               -1135           //Invalide template or unsupported template format
#define MFS100_E_READ_ONLY                  -1136           //Value cannot be modified
#define MFS100_E_NOT_DEFINED                -1137           //Value is not defined
#define MFS100_E_NULL_TEMPLATE              -1138           //Template is NULL (contains no finger)
#define MFS100_E_SYNC_PROBLEM               -1139           //Sync Problem
#define MFS100_E_TIMEOUT                    -1140           //Timeout
#define MFS100_E_UNKNOWN_SENSOR             -1142           //Unknown Sensor
#define MFS100_E_NO_DEVICE                  -1307           //No Device Present
#define MFS100_E_NOT_INITIALIZED            -1309           //Device Not Initialized
#define MFS100_E_CORRUPT_SERIAL             -1314           //Serial no currupted
#define MFS100_E_LOAD_FIRMWARE_FAILED       -1317           //Firmware failed to load
#define MFS100_E_BAD_QUALITY                -1318           //Bad Quality Finger
#define MFS100_E_CAPTURING_STOPPED          -1319           //Capturing stopped
#define MFS100_E_LATENT_FINGER              -1320           //latent finger on device
#define MFS100_E_ALREADY_START_STOP         -1321           //Already start or already stopped
#define MFS100_E_INVALID_KEY                -1322           //Already start or already stopped

#endif
