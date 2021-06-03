int __thiscall GamesenseSDK::Resolver::Resolve(void *this)
{
  int v2; // eax
  float v3; // [esp+0h] [ebp-24h]
  float v4; // [esp+4h] [ebp-20h]
  float v5; // [esp+8h] [ebp-1Ch]
  float v7; // [esp+14h] [ebp-10h]
  int j; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  int i_PlayerID; // [esp+20h] [ebp-4h]

  for ( i = 1; i <= *(_DWORD *)(g_EntityList::MaxPlayers + 24); ++i )
  {
    i_PlayerID = g_Func::GetPlayer(i);
    if ( i_PlayerID
      && (unsigned __int8)g_Player::IsAlive(i_PlayerID)
      && !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)(i_PlayerID + 8) + 36))(i_PlayerID + 8)
      && i_PlayerID != g_Player::LocalPlayer )
    {
      if ( g_Config::ResolverEnabled && (unsigned __int8)g_Func::IsButtonDown(g_Config::ResolverKey) )
        return Resolver::Override(this);
      v2 = g_Func::GetPlayerAnim(i_PlayerID);
      v7 = *(float *)g_Player::m_flCurrentFeetYaw(v2);
      if ( v7 > 58.0 )
      {
        v4 = 58.0 - *(float *)(g_Player::m_angEyeAngles(i_PlayerID) + 4);
        *(float *)(g_Player::m_angEyeAngles(i_PlayerID) + 4) = v4;
      }
      else if ( v7 < -58.0 )
      {
        v5 = *(float *)(g_Player::m_angEyeAngles(i_PlayerID) + 4) + 58.0;
        *(float *)(g_Player::m_angEyeAngles(i_PlayerID) + 4) = v5;
      }
      if ( *(float *)(g_Func::GetAnimOverlay(6) + 40) > 0.1 )
      {
        for ( j = 58; (float)j < -58.0; j = (int)(float)((float)j - 20.0) )
        {
          v3 = (float)j;
          *(float *)(g_Player::m_angEyeAngles(i_PlayerID) + 4) = (float)j;
        }
      }
    }
  }
  return g_Func::NullFunction__();
}
