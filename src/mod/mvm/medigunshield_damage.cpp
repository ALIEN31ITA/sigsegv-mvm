#include "mod.h"


namespace Mod_MvM_MedigunShield_Damage
{
	constexpr uint8_t s_Buf[] = {
		0x89, 0x3c, 0x24,                   // +0000  mov [esp],edi
		0xe8, 0xe8, 0x2f, 0x16, 0x00,       // +0003  call CBaseEntity::GetTeamNumber
		0x83, 0xf8, 0x03,                   // +0008  cmp eax,3
		0x0f, 0x85, 0xbd, 0xfd, 0xff, 0xff, // +000B  jnz -0x243
		0xe9, 0x36, 0xfd, 0xff, 0xff,       // +0011  jmp -0x2ca
	};
	
	struct CPatch_CTFMedigunShield_ShieldTouch : public IPatch
	{
		CPatch_CTFMedigunShield_ShieldTouch() : IPatch(sizeof(s_Buf)) {}
		
		virtual const char *GetFuncName() const override { return "CTFMedigunShield::ShieldTouch"; }
		virtual uint32_t GetFuncOffMin() const override { return 0x02c0; }
		virtual uint32_t GetFuncOffMax() const override { return 0x0300; } // @ 0x2e0
		
		virtual bool GetVerifyInfo(ByteBuf& buf, ByteBuf& mask) const override
		{
			buf.CopyFrom(s_Buf);
			
			mask.SetRange(0x03 + 1, 4, 0x00);
			
			return true;
		}
		
		virtual bool GetPatchInfo(ByteBuf& buf, ByteBuf& mask) const override
		{
			/* make the conditional jump unconditional */
			buf.SetDword(0x0b + 0, 0x90);
			buf.SetDword(0x0b + 1, 0xe9);
			mask.SetRange(0x0b, 2, 0xff);
			
			return true;
		}
	};
	
	
	class CMod : public IMod
	{
	public:
		CMod() : IMod("MvM:MedigunShield_Damage")
		{
			this->AddPatch(new CPatch_CTFMedigunShield_ShieldTouch());
		}
	};
	CMod s_Mod;
	
	
	ConVar cvar_enable("sig_mvm_medigunshield_damage", "0", FCVAR_NOTIFY,
		"Mod: enable damage and stun for robots' medigun shields",
		[](IConVar *pConVar, const char *pOldValue, float flOldValue) {
			ConVarRef var(pConVar);
			s_Mod.Toggle(var.GetBool());
		});
}