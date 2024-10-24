/** Double-include prevention */
#if defined _utl_vector_included
    #endinput
#endif
#define _utl_vector_included

#include <address_base>

#pragma newdecls required
#pragma semicolon 1

// #define UTL_VECTOR_OFFSET_ELEMENTS  0x0
#define UTL_VECTOR_OFFSET_SIZE      0xC

/**
 * Author   dysphie
 * url      https://github.com/dysphie/nmo-guard/blob/main/gamedata/nmo-guard.games.txt
 *          https://github.com/dysphie/nmo-guard/blob/main/scripting/nmo-guard/objective-manager.sp
 *
 * Improve  by F1F88
 * url      https://github.com/F1F88
 * Version  1.0.0
 */


methodmap UtlVector < AddressBase
{
    public UtlVector(Address addr)
    {
        return view_as<UtlVector>(addr);
    }

    property Address elements
    {
        public get()
        {
            if (this.IsNull())
                ThrowError("UtlVector address is null.");

            return LoadFromAddress(this.addr, NumberType_Int32);
            // return view_as<Address>(LoadFromAddress(this.addr + UTL_VECTOR_OFFSET_ELEMENTS, NumberType_Int32));
        }
    }

    property int size
    {
        public get()
        {
            if (this.IsNull())
                ThrowError("UtlVector address is null.");

            return LoadFromAddress(this.addr + UTL_VECTOR_OFFSET_SIZE, NumberType_Int32);
        }

        // 我认为这很危险
        // public set(int value)
        // {
        //     StoreToAddress(this.addr + UTL_VECTOR_OFFSET_SIZE, value, NumberType_Int32);
        // }
    }

    public any Get(int index, NumberType elementSize = NumberType_Int32)
    {
        if (this.IsNull())
            ThrowError("UtlVector address is null.");

        if (index < 0 || index >= this.size)
            ThrowError("Invalid index %d", index);

        Address offset = __UtlVector_CalcElementOffset(index, elementSize);
        return LoadFromAddress(this.elements + offset, elementSize);
    }

    public void Set(int index, any value, NumberType elementSize = NumberType_Int32)
    {
        if (this.IsNull())
            ThrowError("UtlVector address is null.");

        if (index < 0 || index >= this.size)
            ThrowError("Invalid index %d", index);

        Address offset = __UtlVector_CalcElementOffset(index, elementSize);
        StoreToAddress(this.elements + offset, value, elementSize);
    }
}

static Address __UtlVector_CalcElementOffset(int index, NumberType elementSize)
{
    if (elementSize == NumberType_Int8)
        return view_as<Address>(index);

    if (elementSize == NumberType_Int16)
        return view_as<Address>(index * 2);

    return view_as<Address>(index * 4);
}
