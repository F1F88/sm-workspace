/** Double-include prevention */
#if defined _stringt_included
    #endinput
#endif
#define _stringt_included

#include <address_base>

#pragma newdecls required
#pragma semicolon 1

/**
 * Author   dysphie
 * url      https://github.com/dysphie/nmo-guard/blob/main/scripting/nmo-guard/entity-outputs.sp
 *
 * Improve  by F1F88
 * url      https://github.com/F1F88
 * Version  1.0.0
 */


methodmap Stringt < AddressBase
{
    public Stringt(Address addr)
    {
        return view_as<Stringt>(addr);
    }

    /**
     * ><(((°>
     *
     * @param buffer    Buffer to store stringt in.
     * @param maxlen    Maximum length of buffer.
     *
     * @return          store the number of bytes written.
     * @error           stringt address is null or maxlen <= 0.
     */
    public int ToCharArray(char[] buffer, int maxlen)
    {
        if (this.IsNull())
            ThrowError("Stringt address is null.");

        return UTIL_StringtToCharArray(this.addr, buffer, maxlen);
    }
}


/**
 * ><(((°>
 *
 * @param stringt   stringt address.
 * @param buffer    Buffer to store stringt in.
 * @param maxlen    Maximum length of buffer.
 *
 * @return          store the number of bytes written.
 * @error           stringt address is null or maxlen <= 0.
 */
stock int UTIL_StringtToCharArray(Address stringt, char[] buffer, int maxlen)
{
    if (stringt == Address_Null)
        ThrowError("Stringt address is null.");

    if (maxlen <= 0)
        ThrowError("The parameter maxlen must be greater than 0.");

    int  index  = 0;
    int  end    = maxlen - 1;       // 保留 1 位给结束符
    char character;

    while (index < end)             // 读取到 buffer 没有剩余空间或者字符串结束
    {
        character = LoadFromAddress(stringt + index, NumberType_Int8);

        if (character =='\0')       // 字符串结束
            break;

        buffer[index] = character;  // 将字符串内容写入 buffer
        ++index;                    // 将指针移向下一个字符应该存储在 buffer 中的相应下标
    }

    buffer[index] = '\0';           // 结束符
    return index;
}
