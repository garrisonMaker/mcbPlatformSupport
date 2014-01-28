//
//  mcbNetworkMonitor.cpp
//  SoundSurfer
//
//  Created by Radif Sharafullin on 1/27/14.
//
//

#include "mcbNetworkMonitor.h"
namespace mcb{namespace PlatformSupport{namespace network{
    extern const std::string kConnectionTypeChangedNotificationName("kConnectionTypeChangedNotificationName");
    void NetworkMonitor::init(){
        startMonitoring();
    }
    
    
    
#pragma mark -
#pragma mark NetworkNotifier
    NetworkMonitor::ConnectionType NetworkNotifier::connectionType() const{
        return NetworkMonitor::sharedInstance()->connectionType();
    }
    NetworkNotifier::NetworkNotifier(){
        addNotificationHandler(kConnectionTypeChangedNotificationName, [=](){
            connectionStatusChanged(connectionType());
        });
    }
    bool NetworkNotifier::isConnected() const{
        return NetworkMonitor::sharedInstance()->isConnected();
    }

}}}