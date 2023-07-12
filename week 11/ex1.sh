fallocate -l 50M lofs.img
sudo losetup -f lofs.img
losetup
device_name=$(losetup -j lofs.img | grep -Po '/dev/loop\d+')
sudo mkfs.ext4 $device_name
mkdir lofsdisk
sudo mount $device_name lofsdisk
sudo chown $USER lofsdisk