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
            ThrowError("Param index (%d) out of bounds. [0 - %d].", index, this.size);

        Address offset;
        switch (elementSize)
        {
            case NumberType_Int8:
            {
                offset = view_as<Address>(index);
            }
            case NumberType_Int16:
            {
                offset = view_as<Address>(index * 2);
            }
            case NumberType_Int32:
            {
                offset = view_as<Address>(index * 4);
            }
            default:
            {
                ThrowError("Invalid elementSize (%d). [%d, %d, %d]", NumberType_Int8, NumberType_Int16, NumberType_Int32);
            }
        }

        return LoadFromAddress(this.elements + offset, elementSize);
    }

    public void Set(int index, any value, NumberType elementSize = NumberType_Int32)
    {
        if (this.IsNull())
            ThrowError("UtlVector address is null.");

        if (index < 0 || index >= this.size)
            ThrowError("Param index (%d) out of bounds. [0 - %d].", index, this.size);

        Address offset;
        switch (elementSize)
        {
            case NumberType_Int8:
            {
                offset = view_as<Address>(index);
            }
            case NumberType_Int16:
            {
                offset = view_as<Address>(index * 2);
            }
            case NumberType_Int32:
            {
                offset = view_as<Address>(index * 4);
            }
            default:
            {
                ThrowError("Invalid elementSize (%d). [%d, %d, %d]", NumberType_Int8, NumberType_Int16, NumberType_Int32);
            }
        }

        StoreToAddress(this.elements + offset, value, elementSize);
    }
}
