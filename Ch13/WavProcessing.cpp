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
    char                RIFF[4];        // RIFF Header     a.k.a Magic header
    unsigned long       ChunkSize;      // RIFF Chunk Size  
    char                WAVE[4];        // WAVE Header      
    char                FMT[4];         // FMT header       
    unsigned long       Subchunk1Size;  // Size of the fmt chunk                                
    unsigned short      AudioFormat;   // Audio format 1=PCM,6=mulaw,7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM */
    unsigned short      NumOfChan;      // Number of channels 1=Mono 2=Sterio                    
    unsigned long       SamplesPerSec;  // Sampling Frequency in Hz                              
    unsigned long       bytesPerSec;    // bytes per second  
    unsigned short      blockAlign;     // 2=16-bit mono, 4=16-bit stereo  
    unsigned short      bitsPerSample;  // Number of bits per sample  
    char                Subchunk2ID[4]; // "data"  string    
    unsigned long       Subchunk2Size;  // Sampled data length     
}wav_hdr;

union Memory    // Declare union
{
    char block[]; //character array used for when pulling in data
    wav_hdr Info; //The WAV_HEADER variable that seperates it out
};

inline int FileSize(std::ifstream& inFile)
{
    int fileSize = 0;//initialize value
    inFile.seekg(0, ios::end);//set offest to end
    fileSize = inFile.tellg();//read offest value and store it
    inFile.seekg(0, ios::beg);//reset it back to beginning
    return fileSize;
}

inline int WAVExample()
{


    Memory wavHeader;
    int headerSize = sizeof(wav_hdr);//set the headersize
    int filesize = 0;
    ifstream wavFile("../../Ch13/t2_learning_computer_x.wav");//set absolute path of ifstream object
    if (!wavFile )//error handling
    {
        cout << "Can not able to open wave file\n";
        return 1;
    }

    wavFile.read(wavHeader.block, headerSize);//read it in and store the data into the character array for a set size of header

    filesize = FileSize(wavFile);//get the file size
    wavFile.close();//close stream
    cout << "File is " << filesize << " bytes.\n\n";
    cout << "RIFF header\t-->" << string(wavHeader.Info.RIFF, 4) << endl;
    cout << "WAVE header\t-->" << string(wavHeader.Info.WAVE, 4) << endl;
    cout << "FMT\t-->" << string(wavHeader.Info.FMT, 4) << endl;
    cout << "Data size (based on bits used)\t-->" << wavHeader.Info.ChunkSize << endl;

    // Display the sampling Rate form the header
    cout << "Sampling Rate\t-->" << wavHeader.Info.SamplesPerSec << endl; //Sampling frequency of the wav file
    cout << "Number of bits used\t-->" << wavHeader.Info.bitsPerSample << endl; //Number of bits used per sample
    cout << "Number of channels\t-->" << wavHeader.Info.bitsPerSample << endl;     //Number of channels (mono=1/sterio=2)
    cout << "Number of bytes per second\t-->" << wavHeader.Info.bytesPerSec << endl;   //Number of bytes per second
    cout << "data length\t-->" << wavHeader.Info.Subchunk2Size << endl;

    getchar();

    return 0;
}



