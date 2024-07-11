#ifndef _PCM_H
#define _PCM_H

#include <alsa/asoundlib.h>

#include <stdbool.h>
#include <stdint.h>

typedef struct _PcmData PcmData;
struct _PcmData {
  snd_pcm_t *handle;
  int16_t   *Buffer;
  TextStatusCallback OnPCMAbort;
  EventCallback OnPCMDrop;
  int32_t    WindowPtr;
  _Bool      BufferDrop;
};
extern PcmData pcm;

#define PCM_RES_SUCCESS		(0)
#define PCM_RES_SUBOPTIMAL	(-1)
#define PCM_RES_FAILURE		(-2)

int32_t  initPcmDevice (const char *wanteddevname);
void     readPcm       (int32_t numsamples);

#endif
