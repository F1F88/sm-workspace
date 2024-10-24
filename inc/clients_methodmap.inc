/* Figured I would use this section to give credit where credit is due ;)

Special thanks:
- Crasher_3637 (https://forums.alliedmods.net/member.php?u=181166)
	> Valid client check optimization suggestion.
- Ragenewb (https://forums.alliedmods.net/member.php?u=279585)
	> Changing client's team through the 'Team' property suggestion.
- url (https://forums.alliedmods.net/showthread.php?t=307157)
*/

#if defined _gremulock_clients_methodmap_included_
  #endinput
#endif
#define _gremulock_clients_methodmap_included_

#include <clients>

// Method map for clients //

// NOTE: Use valid client checks as you usually would. It is highly recommended to use Player.IsValid!

methodmap Player
{
	public Player(int player) {
		return view_as<Player>(player);
	}

	//=====================//
	// P R O P E R T I E S //
	//=====================//

	/**
	 * Returns the client's index.
	 *
	 * @return				Client's index.
	 */
	property int index {
		public get() {
			return view_as<int>(this);
		}
	}

	/**
	 * Retrieves the client's user id,
	 * which is an index incremented for every client that joins the server.
	 *
	 * @return				User id of the client.
	 * @error 				If the client is not connected or the index is invalid.
	 */
	property int UserId {
		public get() {
			return GetClientUserId(this.index);
		}
	}

	/**
	 * Returns the client's unique serial identifier.
	 *
	 * @return				Serial number.
	 * @error				Invalid client index, or client not connected.
	 */
	property int Serial {
		public get() {
			return GetClientSerial(this.index);
		}
	}

	/**
	 * Returns if a player is valid or not.
	 *
	 * @return				True if player is valid, false otherwise.
	 */
	property bool IsValid {
		public get() {
			return IsValidClient(this.index);
		}
	}

	/**
	 * Returns if a player is connected.
	 *
	 * @return				True if player is connected to the server, false otherwise.
	 */
	property bool IsConnected {
		public get() {
			return IsClientConnected(this.index);
		}
	}

	/**
	 * Returns if a player has entered the game.
	 *
	 * @return				True if player has entered the game, false otherwise.
	 * @error				Invalid client index.
	 */
	property bool InGame {
		public get() {
			return IsClientInGame(this.index);
		}
	}

	/**
	 * Returns if a client is timing out
	 *
	 * @return				True if client is timing out, false otherwise.
	 * @error				Invalid client index, client not connected, or fake client.
	 */
	property bool IsTimingOut {
		public get() {
			return IsClientTimingOut(this.index);
		}
	}

	/**
	 * Returns if a player is in the "kick queue"
	 * (i.e. the client will be kicked shortly and thus they should not appear as valid).
	 *
	 * @return				True if in the kick queue, false otherwise.
	 * @error				Invalid client index.
	 */
	property bool InKickQueue {
		public get() {
			return IsClientInKickQueue(this.index);
		}
	}

	/**
	 * Returns if a player has been authenticated.
	 *
	 * @return				True if player has been authenticated, false otherwise.
	 */
	property bool IsAuthorized {
		public get() {
			return IsClientAuthorized(this.index);
		}
	}

	/**
	 * Returns if a player is a fake client.
	 *
	 * @return				True if player is a fake client, false otherwise.
	 */
	property bool IsFake {
		public get() {
			return IsFakeClient(this.index);
		}
	}

	/**
	 * Returns if a certain player is the SourceTV bot.
	 *
	 * @return				True if player is the SourceTV bot, false otherwise.
	 */
	property bool IsSourceTV {
		public get() {
			return IsClientSourceTV(this.index);
		}
	}

	/**
	 * Returns if a certain player is the Replay bot.
	 *
	 * @return				True if player is the Replay bot, false otherwise.
	 */
	property bool IsReplay {
		public get() {
			return IsClientReplay(this.index);
		}
	}

	/**
	 * Returns if a certain player is an observer/spectator.
	 *
	 * @return				True if player is an observer, false otherwise.
	 */
	property bool IsObserver {
		public get() {
			return IsClientObserver(this.index);
		}
	}

	/**
	 * Returns if the client is alive or dead.
	 *
	 * Note: This function was originally in SDKTools and was moved to core.
	 *
	 * @return				True if the client is alive, false otherwise.
	 * @error				Invalid client index, client not in game, or no mod support.
	 */
	property bool IsAlive {
		public get() {
			return IsPlayerAlive(this.index);
		}
	}

	/**
	 * Returns client access flags.
	 * If the client is not an admin, the result is always 0.
	 *
	 * @return				Flags
	 * @error				Invalid client index, or client not connected.
	 */
	property int FlagBits {
		public get() {
			return GetUserFlagBits(this.index);
		}
	}

	/**
	 * Retrieves a client's team index (and can also change the client's team).
	 *
	 * @return				Team index the client is on (mod specific).
	 * @error				Invalid client index, client not in game, or no mod support.
	 */
	property int Team {
		public get() {
			return GetClientTeam(this.index);
		}
		public set(int team) {
			ChangeClientTeam(this.index, team);
		}
	}

	/**
	 * Returns the client's health.
	 *
	 * @return				Health value.
	 * @error				Invalid client index, client not in game, or no mod support.
	 */
	property int Health {
		public get() {
			return GetClientHealth(this.index);
		}
	}

	/**
	 * Returns the client's death count.
	 *
	 * @return				Death count.
	 * @error				Invalid client index, client not in game, or no mod support.
	 */
	property int Deaths {
		public get() {
			return GetClientDeaths(this.index);
		}
	}

	/**
	 * Returns the client's frag count.
	 *
	 * @return				Frag count.
	 * @error				Invalid client index, client not in game, or no mod support.
	 */
	property int Frags {
		public get() {
			return GetClientFrags(this.index);
		}
	}

	/**
	 * Returns the client's armor.
	 *
	 * @return				Armor value.
	 * @error				Invalid client index, client not in game, or no mod support.
	 */
	property int Armor {
		public get() {
			return GetClientArmor(this.index);
		}
	}

	/**
	 * Returns the client's send data rate in bytes/sec.
	 *
	 * @return				Data rate.
	 * @error				Invalid client index, client not connected, or fake client.
	 */
	property int DataRate {
		public get() {
			return GetClientDataRate(this.index);
		}
	}

	/**
	 * Returns the client's connection time in seconds.
	 *
	 * @return				Connection time.
	 * @error				Invalid client index, client not connected, or fake client.
	 */
	property float ConnectionTime {
		public get() {
			return GetClientTime(this.index);
		}
	}

	//=====================//
	//  F U N C T I O N S  //
	//=====================//

	/**
	 * Returns the client's name.
	 *
	 * @param name			Buffer to store the client's name.
	 * @param maxlen		Maximum length of string buffer (includes NULL terminator).
	 * @return				True on success, false otherwise.
	 * @error				If the client is not connected an error will be thrown.
	 */
	public bool GetName(char[] name, int maxlen) {
		return GetClientName(this.index, name, maxlen);
	}

	/**
	 * Retrieves the client's IP address.
	 *
	 * @param ip			Buffer to store the client's ip address.
	 * @param maxlen		Maximum length of string buffer (includes NULL terminator).
	 * @param remport		Remove client's port from the ip string (true by default).
	 * @return				True on success, false otherwise.
	 * @error				If the client is not connected or the index is invalid.
	 */
	public bool GetIP(char[] ip, int maxlen, bool remport=true) {
		return GetClientIP(this.index, ip, maxlen, remport);
	}

	/**
	 * Retrieves the client's authentication string (SteamID).
	 *
	 * @param authType		Auth id type and format to use.
	 * @param auth			Buffer to store the client's auth id.
	 * @param maxlen		Maximum length of string buffer (includes NULL terminator).
	 * @param validate		Check backend validation status.
	 * 						DO NOT PASS FALSE UNLESS YOU UNDERSTAND THE CONSEQUENCES,
	 *						You WILL KNOW if you need to use this, MOST WILL NOT.
	 * @return				True on success, false otherwise.
	 * @error				If the client is not connected or the index is invalid.
	 */
	public bool GetAuthId(AuthIdType authType, char[] auth, int maxlen, bool validate=true) {
		return GetClientAuthId(this.index, authType, auth, maxlen, validate);
	}

	/**
	 * Returns the client's Steam account ID.
	 *
	 * @param validate		Check backend validation status.
	 *						DO NOT PASS FALSE UNLESS YOU UNDERSTAND THE CONSEQUENCES,
	 *						You WILL KNOW if you need to use this, MOST WILL NOT.
	 * @return				Steam account ID or 0 if not available.
	 * @error				If the client is not connected or the index is invalid.
	 */
	public int GrabSteamAccountID(bool validate=true) {
		return GetSteamAccountID(this.index, validate);
	}

	/**
	 * Retrieves values from client replicated keys.
	 *
	 * @param key			Key string.
	 * @param value			Buffer to store value.
	 * @param maxlen		Maximum length of valve (UTF-8 safe).
	 * @return 				True on success, false otherwise.
	 * @error				Invalid client index, or client not connected.
	 */
	public bool GetInfo(const char[] key, char[] value, int maxlen) {
		return GetClientInfo(this.index, key, value, maxlen);
	}

	/**
	 * Sets access flags on a client using bits instead of flags.
	 * If the client is not an admin, and flags not 0, a temporary, anonymous AdminId is given.
	 *
	 * @param flags			Bitstring of flags to set on client.
	 */
	public void SetFlagBits(int flags) {
		SetUserFlagBits(this.index, flags);
	}

	/**
	 * Returns whether a user can target another user.
	 * This is a helper function for CanAdminTarget.
	 *
	 * @param target		Target player's index.
	 * @return				True if target is targettable by the player, false otherwise.
	 * @error				Invalid or unconnected player indexers.
	 */
	public bool CanTarget(int target) {
		return CanUserTarget(this.index, target);
	}

	/**
	 * Runs through the Core-defined admin authorization checks on a player.
	 * Has no effect if the player is already an admin.
	 *
	 * Note: This function is based on the internal cache only.
	 *
	 * @return				True if access was changed, false if it did not.
	 * @error				Invalid client index or client not in-game AND authorized.
	 */
	public bool AdminCacheCheck() {
		return RunAdminCacheChecks(this.index);
	}

	/**
	 * Signals that a player has completed post-connection admin checks.
	 * Has no effect if the player has already had this event signalled.
	 *
	 * Note: This must be sent even if no admin id was assigned.
	 *
	 * @error				Invalid client index or client not in-game AND authorized.
	 */
	public void PostAdminCheck() {
		NotifyPostAdminCheck(this.index);
	}

	/**
	 * Returns the client's model name.
	 *
	 * @param model			Buffer to store the client's model name.
	 * @param maxlen		Maximum length of string buffer (includes NULL terminator).
	 * @error				Invalid client index, client not in game, or no mod support.
	 */
	public void GetModel(char[] model, int maxlen) {
		GetClientModel(this.index, model, maxlen);
	}

	/**
	 * Returns the client's weapon name.
	 *
	 * @param weapon		Buffer to store the client's weapon name.
	 * @param maxlen		Maximum length of string buffer (includes NULL terminator).
	 * @error				Invalid client index, client not in game, or no mod support.
	 */
	public void GetWeapon(char[] weapon, int maxlen) {
		GetClientWeapon(this.index, weapon, maxlen);
	}

	/**
	 * Returns the client's max size vector.
	 *
	 * @param vec			Destination vector to store the client's max size.
	 * @error				Invalid client index, client not in game, or no mod support.
	 */
	public void GetMaxs(float vec[3]) {
		GetClientMaxs(this.index, vec);
	}

	/**
	 * Returns the client's min size vector.
	 *
	 * @param vec			Destination vector to store the client's min size.
	 * @error				Invalid client index, client not in game, or no mod support.
	 */
	public void GetMins(float vec[3]) {
		GetClientMins(this.index, vec);
	}

	/**
	 * Returns the client's position angle.
	 *
	 * @param ang			Destination vector to store the client's position angle.
	 * @error				Invalid client index, client not in game, or no mod support.
	 */
	public void GetAbsAngles(float ang[3]) {
		GetClientAbsAngles(this.index, ang);
	}

	/**
	 * Returns the client's origin vector.
	 *
	 * @param vec			Destination vector to store the client's origin vector.
	 * @error				Invalid client index, client not in game, or no mod support.
	 */
	public void GetAbsOrigin(float vec[3]) {
		GetClientAbsOrigin(this.index, vec);
	}

	/**
	 * Returns the client's current latency (RTT), more accurate than GetAvgLatency but jittering.
	 *
	 * @param flow			Traffic flowing direction.
	 * @return				Latency, or -1 if network info is not available.
	 * @error				Invalid client index, client not connected, or fake client.
	 */
	public float GetLatency(NetFlow flow) {
		return GetClientLatency(this.index, flow);
	}

	/**
	 * Returns the client's average packet latency in seconds.
	 *
	 * @param flow			Traffic flowing direction.
	 * @return				Latency, or -1 if network info is not available.
	 * @error				Invalid client index, client not connected, or fake client.
	 */
	public float GetAvgLatency(NetFlow flow) {
		return GetClientAvgLatency(this.index, flow);
	}

	/**
	 * Returns the client's average packet loss, values go from 0 to 1 (for percentages).
	 *
	 * @param flow			Traffic flowing direction.
	 * @return				Average packet loss, or -1 if network info is not available.
	 * @error				Invalid client index, client not connected, or fake client.
	 */
	public float GetAvgLoss(NetFlow flow) {
		return GetClientAvgLoss(this.index, flow);
	}

	/**
	 * Returns the client's average packet choke, values go from 0 to 1 (for percentages).
	 *
	 * @param flow			Traffic flowing direction.
	 * @return				Average packet loss, or -1 if network info is not available.
	 * @error				Invalid client index, client not connected, or fake client.
	 */
	public float GetAvgChoke(NetFlow flow) {
		return GetClientAvgChoke(this.index, flow);
	}

	/**
	 * Returns the client's data flow in bytes/sec.
	 *
	 * @param flow			Traffic flowing direction.
	 * @return				Data flow.
	 * @error				Invalid client index, client not connected, or fake client.
	 */
	public float GetAvgData(NetFlow flow) {
		return GetClientAvgData(this.index, flow);
	}

	/**
	 * Returns the client's average packet frequency in packets/sec.
	 *
	 * @param flow			Traffic flowing direction.
	 * @return				Packet frequency.
	 * @error				Invalid client index, client not connected, or fake client.
	 */
	public float GetAvgPackets(NetFlow flow) {
		return GetClientAvgPackets(this.index, flow);
	}

	/**
	 * Changes a client's team through the mod's generic team changing function.
	 * On CS:S, this will kill the player.
	 *
	 * @param team			Mod-specific team index.
	 * @error				Invalid client index, client not connected, or lack of
	 *						mod support.
	 */
	public void ChangeTeam(int team) {
		ChangeClientTeam(this.index, team);
	}

	/**
	 * Disconnects a client from the server as soon as the next frame starts.
	 *
	 * Note: Originally, KickClient() was immediate.
	 * The delay was introduced because despite warnings, plugins were using it in ways that would crash.
	 * The new safe version can break cases that rely on immediate disconnects, but ensures that plugins
	 * do not accidentally cause crashes.
	 *
	 * If you need immediate disconnects, use KickClientEx().
	 *
	 * Note: IsClientInKickQueue() will return true before the kick occurs.
	 *
	 * @param format		Optional formatting rules for disconnect reason.
	 * 						Note that a period is automatically appended to the string by the engine.
	 * @param ...			Variable number of format parameters.
	 * @error				Invalid client index, or client not connected.
	 */
	public void Kick(const char[] format="", any ...) {
		if (format[0] == '\0')
			KickClient(this.index, "No reason given");
		else {
			char message[256];
			VFormat(message, sizeof(message), format, 3);
			KickClient(this.index, message);
		}
	}

	/**
	 * Immediately disconnects a client from the server.
	 *
	 * Kicking clients from certain events or callbacks may cause crashes.
	 * If in doubt, create a short (0.1 second) timer to kick the client in the next available frame.
	 *
	 * @param format		Optional formatting rules for disconnect reason.
	 * 						Note that a period is automatically appended to the string by the engine.
	 * @param ...			Variable number of format parameters.
	 * @error				Invalid client index, or client not connected.
	 */
	public void KickEx(const char[] format="", any ...) {
		if (format[0] == '\0')
			KickClientEx(this.index, "No reason given");
		else {
			char message[256];
			VFormat(message, sizeof(message), format, 3);
			KickClientEx(this.index, message);
		}
	}
}

/**
* Check whether or not a client is valid.
*
* @param client 	Client being checked.
* @return			True if client is valid, false otherwise.
**/
stock bool IsValidClient(int client)
{
	return client > 0 && client <= MaxClients && IsClientInGame(client);
}
