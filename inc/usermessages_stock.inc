/** Double-include prevention */
#if defined _usermessages_stock_included
    #endinput
#endif
#define _usermessages_stock_included

#include <usermessages>

#pragma newdecls required
#pragma semicolon 1

/**
 * Author   F1F88
 * url      https://github.com/F1F88
 * Version  1.0.1
 */


stock void SendMessageKeyHintText(const int[] clients, int numClients, int flags = 0, const char[] format, any ...)
{
    static UserMsg messageId = INVALID_MESSAGE_ID;
    if (messageId == INVALID_MESSAGE_ID)
    {
        if ((messageId = GetUserMessageId("KeyHintText")) == INVALID_MESSAGE_ID)
        {
            ThrowError("message KeyHintText not found!");
        }
    }

    static char text[256];
    VFormat(text, sizeof(text), format, 5);
    Handle message = StartMessageEx(messageId, clients, numClients, flags);
    BfWriteByte(message, 1); // one message
    BfWriteString(message, text);
    EndMessage();
}

stock void SendMessageKeyHintTextAll(int flags = 0, const char[] format, any ...)
{
    int total = 0;
    int[] clients = new int[MaxClients];
    for (int i = 1; i <= MaxClients; i++)
    {
        if (IsClientInGame(i))
        {
            clients[total++] = i;
        }
    }

    if (total != 0)
    {
        static UserMsg messageId = INVALID_MESSAGE_ID;
        if (messageId == INVALID_MESSAGE_ID)
        {
            if ((messageId = GetUserMessageId("KeyHintText")) == INVALID_MESSAGE_ID)
            {
                ThrowError("message KeyHintText not found!");
            }
        }

        static char text[256];
        VFormat(text, sizeof(text), format, 3);
        Handle message = StartMessageEx(messageId, clients, total, flags);
        BfWriteByte(message, 1); // one message
        BfWriteString(message, text);
        EndMessage();
    }
}

stock void SendMessageKeyHintTextOne(int client, int flags = 0, const char[] format, any ...)
{
    int clients[1];
    clients[0] = client;

    static UserMsg messageId = INVALID_MESSAGE_ID;
    if (messageId == INVALID_MESSAGE_ID)
    {
        if ((messageId = GetUserMessageId("KeyHintText")) == INVALID_MESSAGE_ID)
        {
            ThrowError("message KeyHintText not found!");
        }
    }

    static char text[256];
    VFormat(text, sizeof(text), format, 4);
    Handle message = StartMessageEx(messageId, clients, 1, flags);
    BfWriteByte(message, 1); // one message
    BfWriteString(message, text);
    EndMessage();
}


/**
 * Author   dysphie
 * url      https://github.com/dysphie/nmrih-team-healing/blob/c68dcc687c943be9927656e07f880e66e174651f/scripting/nmrih-team-healing.sp#L830
 */
stock void SendMessageProgressBarShowOne(int client, float duration, float prefill = 0.0)
{
    BfWrite bf = UserMessageToBfWrite(StartMessageOne("ProgressBarShow", client));
    bf.WriteFloat(duration);
    bf.WriteFloat(prefill);
    EndMessage();
}

/**
 * Author   dysphie
 * url      https://github.com/dysphie/nmrih-team-healing/blob/c68dcc687c943be9927656e07f880e66e174651f/scripting/nmrih-team-healing.sp#L838
 */
stock void SendMessageProgressBarHideOne(int client)
{
    StartMessageOne("ProgressBarHide", client);
    EndMessage();
}
