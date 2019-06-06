<template>
  <div class="text-xs-center">
    <v-progress-circular
      :rotate="-90"
      :size="300"
      :width="100"
      :value="value"
      color="primary"
    >
      {{ value + " %"}}
    </v-progress-circular>
  </div>
</template>

<style lang="stylus" scoped>
  .v-progress-circular
    margin: 0rem
</style>

<script>
  export default {
    data () {
      return {
        interval: {},
        value: 0
      }
    },
    beforeDestroy () {
      clearInterval(this.interval)
    },
    mounted () {
      this.interval = setInterval(() => {
        if (this.value === 100) {
          return (this.value = 0)
        }
        this.value += 10
      }, 1000)
    }
  }
</script>