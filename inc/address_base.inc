/** Double-include prevention */
#if defined _address_base_included
    #endinput
#endif
#define _address_base_included

#pragma newdecls required
#pragma semicolon 1

/**
 * Author   dysphie
 * url      https://github.com/dysphie/nmo-guard/blob/main/scripting/nmo-guard/objective-manager.sp
 *
 * Improve  by F1F88
 * url      https://github.com/F1F88
 * Version  1.0.0
 */


stock Address operator+(Address base, int offset)
{
    return base + view_as<Address>(offset);
}

stock Address operator-(Address base, int offset)
{
    return base - view_as<Address>(offset);
}

stock Address operator*(Address base, int offset)
{
    return base * view_as<Address>(offset);
}

stock Address operator/(Address base, int offset)
{
    return base / view_as<Address>(offset);
}


methodmap AddressBase
{
    property Address addr
    {
        public get()
        {
            return view_as<Address>(this);
        }
    }

    public bool IsNull()
    {
        return this.addr == Address_Null;
    }
}

