#pragma once

#include "OnlineUserGOG.h"

class FUserOnlineAccountGOG : public FUserOnlineAccount, public FOnlineUserGOG
{
public:

	static TSharedRef<FUserOnlineAccountGOG> CreateOwn();

	explicit FUserOnlineAccountGOG(FUniqueNetIdGOG InUserID);

	explicit FUserOnlineAccountGOG(FUniqueNetIdGOG InUserID, FString InDisplayName, FString InAccessToken = {});

	// FOnlineUser interface implementation

	TSharedRef<const FUniqueNetId> GetUserId() const override;

	FString GetRealName() const override;

	FString GetDisplayName(const FString& InPlatform = FString()) const override;

	bool GetUserAttribute(const FString& InAttrName, FString& OutAttrValue) const override;

	// FUserOnlineAccount interface implementation

	bool SetUserAttribute(const FString& InAttrName, const FString& InAttrValue) override;

	FString GetAccessToken() const override;

	bool GetAuthAttribute(const FString& InAttrName, FString& OutAttrValue) const override;

private:

	FUserOnlineAccountGOG() = delete;

	FString accessToken;
};
