/**
 * Copyright (C) JoyStream - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Lola Rigaut-Luczak <rllola80@gmail.com>, January 18 2017
 */

#ifndef LIBTORRENT_NODE_ADD_TORRENT_PARAMS_HPP
#define LIBTORRENT_NODE_ADD_TORRENT_PARAMS_HPP

#include <nan.h>
#include <boost/cstdint.hpp>

// The add_torrent_params is a parameter pack for adding torrents to a
// session. The key fields when adding a torrent are:
//
// * ti - when you have a .torrent file
// * url - when you have a magnet link
// * info_hash - when all you have is an info-hash (this is similar to a
//   magnet link)
//

namespace libtorrent {
    struct add_torrent_params;
namespace node {
namespace add_torrent_params {

  /**
     AddTorrentParams is encoded as
    {
      ti : { see String or Buffer },
      name : { String },
      save_path : { String },
      info_hash : { see sha1_hash format },
      url : { String },
      resume_data :  { String },
      upload_limit : { Number },
      download_limit : { Number }
      flags: {
        seed_mode: [boolean],
        override_resume_data: [boolean],
        upload_mode: [boolean],
        share_mode: [boolean],
        apply_ip_filter: [boolean],
        paused: [boolean],
        auto_managed: [boolean],
        duplicate_is_error: [boolean],
        merge_resume_trackers: [boolean],
        update_subscribe: [boolean],
        super_seeding: [boolean],
        sequential_download: [boolean],
        use_resume_save_path: [boolean],
        pinned: [boolean],
        merge_resume_http_seeds: [boolean],
        stop_when_ready: [boolean],
      }
     }
   */

 v8::Local<v8::Object> encode(const libtorrent::add_torrent_params & atp);
 libtorrent::add_torrent_params decode(const v8::Local<v8::Value> & o);

namespace flags {
  v8::Local<v8::Object> encode(const boost::uint64_t &flags);
  boost::uint64_t decode(const v8::Local<v8::Value> & o);
}

}
}
}

#endif // LIBTORRENT_NODE_ADD_TORRENT_PARAMS_HPP
