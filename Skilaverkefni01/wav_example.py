import math
import struct

def makeWaveHeader(sampleRate, noChannels, bitsSample):

   # Compute values of header fields

   noSamples  = duration * sampleRate    # Total number of samples for file
   byteRate   = int(sampleRate * noChannels * bitsSample/8)
   blockAlign = int(noChannels * bitsSample/8)


   int_field = 0     # Dummy variable for size fields that get filled in later

   # Header fields must be created in the following order.
   wave = bytearray("RIFF", 'utf-8')
   print(wave)
   wave.extend(int_field.to_bytes(4,'little')) # For Chunk Size
   print(wave)
   wave.extend("WAVEfmt ".encode('utf-8'))
   print(wave)
   formatSize = 16   # PCM
   wave.extend(formatSize.to_bytes(4,'little')) # For sub chunk Size
   print(wave)
   wave.extend(b'\x01\x00')    # Audio Format PCM(Pulse-Code Modulation)
   wave.extend(b'\x01\x00')    # No. of Channels, Mono = 1, Stereo = 2
   print(wave)
   wave.extend(sampleRate.to_bytes(4,'little'))  # Sample Rate
   print(wave)
   wave.extend(byteRate.to_bytes(4, 'little'))   # Byte Rate
   print(wave)
   wave.extend(blockAlign.to_bytes(2, 'little'))
   print(wave)
   wave.extend(bitsSample.to_bytes(2, 'little'))
   print(wave)

   # Data Subchunk 
   # Chunk sizes vary with data, so must be updated with each new sample:
   #
   #  Initialisation:
   #  Chunk Size  = 4 + (8 + 16 (PCM chunk size)) + (8 + subchunksize)
   #  Sub Chunk Size = nSamples * nChannels * bitsSample/8
   #
   #  Update
   #  Chunk Size     += (noChannels * bitsSample/8)
   #  Sub Chunk Size += (noChannels * bitsSample/8)

   wave.extend("data".encode('utf-8'))
   print(wave)
   chunkSize = 4 + 8 + 16 + 8 + 0
   wave[4:8] = chunkSize.to_bytes(4, 'little')    # Chunk size
   print(wave)
   wave[40:44] = int_field.to_bytes(4,'little')   # Sub Chunk size
   print(wave)
   return wave

#
# Convert the supplied sample to an int in 
#

def addSample(wave, sample):
   sample_16 = (int)(sample * 32767)
   data = struct.pack('<h', sample_16)
   wave.extend(data)

if __name__ == "__main__":

   sampleRate = 44100      # Sample rate in Hz. (CD quality)
   freq       = 440        # A above middle C
   duration   = 0.5        # Length of tone - seconds
   noChannels = 1          # Mono

   noSamples  = int(duration * sampleRate)   # Total number of samples for file

   # Create the header for the wave file
   wave = makeWaveHeader(sampleRate, noChannels, 16)

   # Add frequency samples
   for i in range(0, noSamples):
       sample = math.cos(freq * i * 3.142/sampleRate) 
       addSample(wave, sample)

   # Update chunk and subchunk sizes

   dataBytes   = int(duration * sampleRate * noChannels * 16/8)
   wave[40:44] = dataBytes.to_bytes(4,'little')   # Sub Chunk size
   dataBytes += 4 + 8 + 16 + 8             # Header size
   wave[4:8] = dataBytes.to_bytes(4, 'little')

   #write out to file
   fptr = open("example.wav", "w+b")
   fptr.write(wave)
   fptr.close()
