//
//  mcbAudioCache.h
//  ColorDots
//
//  Created by Radif Sharafullin on 8/29/13.
//
//

#ifndef __ColorDots__mcbAudioCache__
#define __ColorDots__mcbAudioCache__

#include "mcbAudioPlayer.h"
#include <map>

namespace mcb{namespace PlatformSupport{
    class AudioCache{
        std::map<std::string, std::pair<pAudioPlayer, int>> _players;//retian counted
    public:
        static AudioCache* sharedInstance();
        
        pAudioPlayer loadSound(const std::string & path, const std::string & key="");
        pAudioPlayer playerForSound(const std::string & pathOrKey);
        
        pAudioPlayer playAudioSound(const std::string & pathOrKey);
        pAudioPlayer stopAudioSound(const std::string & pathOrKey);
        
        void iterateThroughSounds(std::function<void(const std::string & pathOrKey, pAudioPlayer player)> handle);
        
        void unloadSound(const std::string & pathOrKey);
        void drain();
    };
}}

#endif /* defined(__ColorDots__mcbAudioCache__) */
