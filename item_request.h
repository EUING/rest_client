#ifndef MONITOR_CLIENT_ITEM_REQUEST_H_
#define MONITOR_CLIENT_ITEM_REQUEST_H_

#include <memory>
#include <string>

#include "common_struct.h"
#include "item_http.h"
#include "local_db.h"

namespace monitor_client {
	class ItemRequest {
	public:
		ItemRequest(const common_utility::NetworkInfo& network_info, std::unique_ptr<ItemDao>&& item_dao);
		ItemRequest(const std::shared_ptr<ItemHttp>& item_http, const std::shared_ptr<LocalDb>& local_db);

		ItemRequest(const ItemRequest&) = delete;
		ItemRequest& operator=(const ItemRequest&) = delete;

		ItemRequest(ItemRequest&&) = default;
		ItemRequest& operator=(ItemRequest&&) = default;

		~ItemRequest() = default;

		bool UploadRequest(const common_utility::ItemInfo& item_info);
		bool DownloadRequest(const std::wstring& relative_path);
		bool RenameRequest(const common_utility::ChangeNameInfo& change_name_info);
		bool RemoveRequest(const std::wstring& relative_path);
		bool LocalRemoveRequest(const std::wstring& relative_path);

	private:
		std::shared_ptr<ItemHttp> item_http_;
		std::shared_ptr<LocalDb> local_db_;
	};
}  // namespace monitor_client
#endif