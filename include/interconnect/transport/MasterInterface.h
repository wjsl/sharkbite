/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SRC_INTERCONNECT_MASTERINTERFACE_H_
#define SRC_INTERCONNECT_MASTERINTERFACE_H_


#include <concurrency/ThreadManager.h>

#include <chrono>
#include <thread>
#include <sys/time.h>

#include <map>
#include <set>
#include <string>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand





#include "../../data/constructs/inputvalidation.h"
#include "../../data/constructs/IterInfo.h"
#include "../../data/constructs/configuration/Configuration.h"
#include "../../data/extern/thrift/data_types.h"
#include "../../data/extern/thrift/tabletserver_types.h"
#include "../../data/constructs/scanstate.h"
#include "../../data/exceptions/ClientException.h"
#include "../../data/exceptions/IllegalArgumentException.h"
#include "../../data/constructs/tablet/TabletType.h"
#include "../scanrequest/ScanIdentifier.h"

#include "Transport.h"
#include <boost/concept_check.hpp>
#include <boost/shared_ptr.hpp>

#include "../../data/extern/thrift/ClientService.h"
#include "../../data/extern/thrift/master_types.h"
#include "../../data/extern/thrift/MasterClientService.h"
#include "../../data/extern/thrift/ThriftWrapper.h"
#include "../../data/constructs/security/AuthInfo.h"
#include "../Scan.h"




#include <protocol/TCompactProtocol.h>
#include <server/TSimpleServer.h>

#include <transport/TServerSocket.h>
#include <transport/TServerTransport.h>
#include <transport/TTransport.h>
#include <transport/TSocket.h>
#include <transport/TTransportException.h>
#include <transport/TBufferTransports.h>

namespace interconnect
{

/**
 * Pure virtual class that represents the master interface
 * 
 **/
class MasterInterface
{
public:
  /**
   * Recreates the master client, usually upon error.
   **/ 
  virtual void recreateMasterClient() = 0;
  /**
   * Recreates a thrift transporter. This will usually happen upon error
   * @return a new thrift transport
   **/
  virtual boost::shared_ptr<apache::thrift::transport::TTransport> recreateTransport() = 0;
  /**
   * Returns the master client
   * @return new thrift master client
   **/
  virtual org::apache::accumulo::core::master::thrift::MasterClientServiceClient *getMasterClient() = 0;
  
};

}

#endif
