//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef SLAVE_H_
#define SLAVE_H_

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include "Message.h"
#include "State.h"

using namespace omnetpp;


namespace earthquakedetector {

class Slave : public cSimpleModule{
    public:
        Slave();
        virtual ~Slave();

    private:
        long numSent;
        long numReceived;
        std::string id;
        State state;

    protected:
        virtual Message *generateMessage();
        virtual void forwardMessage(Message *msg);
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
        virtual void refreshDisplay() const override;
};

} /* namespace earthquakedetector */

#endif /* SLAVE_H_ */
