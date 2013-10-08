/*
  Lockbox: Encrypted File System
  Copyright (C) 2013 Rian Hunter <rian@alum.mit.edu>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

/* a C Fs to EncFS FsIO translator */

#ifndef _CFsToFsIO_incl_
#define _CFsToFsIO_incl_

#include "c_fs_to_fs_io_fs.h"

#include <encfs/fs/FsIO.h>

namespace lockbox {

class CFsToFsIO : public encfs::FsIO {
private:
  fs_t _fs;

public:
  CFsToFsIO(fs_t fs);
  virtual ~CFsToFsIO() override = default;

  // generic fs methods
  virtual const std::string &path_sep() const override;
  virtual encfs::Path pathFromString(const std::string &path) const override;

  virtual encfs::Directory opendir(const encfs::Path &path) const override;
  virtual encfs::File openfile(const encfs::Path &path,
                               bool open_for_write = false,
                               bool create = false) override;

  virtual void mkdir(const encfs::Path &path) override;

  virtual void rename(const encfs::Path &pathSrc, const encfs::Path &pathDst) override;

  virtual void unlink(const encfs::Path &path) override;
  virtual void rmdir(const encfs::Path &path) override;

  virtual void set_times(const encfs::Path &path,
                         const opt::optional<encfs::fs_time_t> &atime,
                         const opt::optional<encfs::fs_time_t> &mtime) override;
};

}

#endif
