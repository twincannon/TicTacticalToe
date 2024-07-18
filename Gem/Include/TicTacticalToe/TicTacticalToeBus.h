
#pragma once

#include <TicTacticalToe/TicTacticalToeTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace TicTacticalToe
{
    class TicTacticalToeRequests
    {
    public:
        AZ_RTTI(TicTacticalToeRequests, TicTacticalToeRequestsTypeId);
        virtual ~TicTacticalToeRequests() = default;
        // Put your public methods here
    };

    class TicTacticalToeBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using TicTacticalToeRequestBus = AZ::EBus<TicTacticalToeRequests, TicTacticalToeBusTraits>;
    using TicTacticalToeInterface = AZ::Interface<TicTacticalToeRequests>;

} // namespace TicTacticalToe
