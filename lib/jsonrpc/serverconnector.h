/**
 * @file serverconnector.h
 * @date 31.12.2012
 * @author Peter Spiess-Knafl <peter.knafl@gmail.com>
 * @brief to be defined
 */

#ifndef SERVERCONNECTOR_H_
#define SERVERCONNECTOR_H_

#include "requesthandler.h"

namespace jsonrpc
{
    
    class ServerConnector
    {
        public:
            ServerConnector();
            virtual ~ServerConnector();

            /**
             * This method should signal the Connector to start waiting for requests, in any way that is appropriate for the derived connector class.
             * If something went wrong, this method should return false, otherwise true.
             */
            virtual bool StartListening() = 0;
            /**
             * This method should signal the Connector to stop waiting for requests, in any way that is appropriate for the derived connector class.
             * If something went wrong, this method should return false, otherwise true.
             */
            virtual bool StopListening() = 0;

            /**
             * This method should send a response to the client in any way that is appropriate for the derived connector class.
             * @param response - the response that should be send to the client
             * @param addInfo - additional Info, that the Connector might need for responding.
             * @return returns true on success, false otherwise
             */
            bool virtual SendResponse(const std::string& response,
                    void* addInfo = NULL) = 0;

            /**
             * This method must be called, when a request is recognised. It will do everything else for you (including sending the response).
             * @param request - the request that has been recognised.
             * @param addInfo - additional Info, that the Connector might need for responding.
             */
            bool OnRequest(const std::string& request, void* addInfo = NULL);

            void SetHandler(RequestHandler* handler)
            {
                this->handler = handler;
            }

        private:
            RequestHandler* handler;
    };

} /* namespace jsonrpc */
#endif /* SERVERCONNECTOR_H_ */
