#include <conio.h>     /* include for kbhit() and getch() functions */
#include <iostream>
#include <windows.h>   /* required before including mmsystem.h */
#include <mmsystem.h>  /* multimedia functions (such as MIDI) for Windows */
#include <atlstr.h>
#include <fstream>
#pragma comment(lib, "Winmm.lib") //Link the Winmm.lib to the EXE
using namespace std;

typedef struct  WAV_HEADER
{
    char                riff[4];        // RIFF Header
    unsigned long       chunksize;      // RIFF Chunk Size  
    char                wave[4];        // WAVE Header      
    char                fmt[4];         // FMT header       
    unsigned long       subchunk1Size;  // Size of the fmt chunk                                
    unsigned short      audioFormat;   // Audio format code 1=PCM,6=mulaw,7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM */
    unsigned short      numOfChannels;      // Number of channels 1=Mono 2=Stereo                    
    unsigned long       samplesPerSec;  // Sampling frequency in Hz                              
    unsigned long       bytesPerSec;    // bytes per second  
    unsigned short      blockAlign;     // 2=16-bit mono, 4=16-bit stereo  
    unsigned short      bitsPerSample;  // Number of bits per sample  
    char                subchunk2ID[4]; // "data" of song in string    
    unsigned long       subchunk2Size;  // Sampled data length     
}wav_header;


union Memory   
{
    char block[]; //character array 
    wav_header Info; //The WAV_HEADER variable that seperates it out
};

inline int FileSize(std::ifstream& inFile)
{
    int fileSize = 0;//initialize value
    inFile.seekg(0, ios::end);//set offest to end
    fileSize = inFile.tellg();//read offest value and store it
    inFile.seekg(0, ios::beg);//reset it back to beginning
    return fileSize;
}

inline BOOL PlayWav(string filePath)
{
   BOOL played = PlaySoundW((CString)filePath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
   if(played)
        system("PAUSE");

    return played;

}




inline int WAVExample(string filePath)
{
    Memory wavHeader;
    int headerSize = sizeof(wav_header);//set the headersize
    int filesize = 0;
    ifstream wavFile(filePath);//set absolute path of ifstream object
    if (!wavFile )//error handling
    {
        cout << "Can not able to open wave file\n";
        return 1;
    }

    wavFile.read(wavHeader.block, headerSize);

    filesize = FileSize(wavFile);//get the file size
    wavFile.close();//close stream
    cout << "File is " << filesize << " bytes.\n\n";
    cout << "RIFF header\t-->" << string(wavHeader.Info.riff, 4) << endl;
    cout << "WAVE header\t-->" << string(wavHeader.Info.wave, 4) << endl;
    cout << "FMT\t-->" << string(wavHeader.Info.fmt, 4) << endl;
    cout << "Data size (based on bits used)\t-->" << wavHeader.Info.chunksize << endl;
    cout << "Sampling Rate\t-->" << wavHeader.Info.samplesPerSec << endl; 
    cout << "Number of bits used\t-->" << wavHeader.Info.bitsPerSample << endl;
    cout << "Number of channels\t-->" << wavHeader.Info.bitsPerSample << endl;    
    cout << "Number of bytes per second\t-->" << wavHeader.Info.bytesPerSec << endl;  
    cout << "data length\t-->" << wavHeader.Info.subchunk2Size << endl;

    getchar();

    return 0;
}



